# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


BLACK = False
RED = True


class TreeNode:
    # 1. 在红黑树中，红色的节点代表的就是它和它的父亲在 2-3 树中是在融合在一起的
    # 2. 在 2-3 树中插入新建的节点的时候，都是先和叶子节点进行融合
    def __init__(self, data, left=None, right=None, color=RED):
        self.data = data
        self.left = left
        self.right = right
        # 颜色
        self.color = color


class BSTR:
    def __init__(self, __comp):
        self.root = None
        self.size = 0
        self.__comp = __comp

    def getSize(self):
        return self.size

    def isEmpty(self):
        return self.size == 0

    # 判断一个节点是否是红色的
    def isRED(self, node):
        # 根据红黑树的定义，空节点的颜色是黑色的
        if not node:
            return BLACK
        return node.color

    """
        node                    x
        /  \       左旋转      /   \
       T1   x     ------->  node  T3
           / \              /  \
          T2 T3            T1  T2
    """
    def leftRotate(self, node):
        x = node.right

        # 左旋
        node.right = x.left
        x.left = node

        x.color = node.color
        node.color = RED

        return x

    # 颜色翻转
    def flipColors(self, node):
        node.color = RED
        node.left.color = BLACK
        node.right.color = BLACK

    """
        node                    x
        /  \       右旋转      /   \
       x   T2     ------->   y   node
      / \                        /  \
     y  T1                      T1  T2
    """
    def rightRotate(self, node):
        x = node.left
        # 右旋
        node.left = x.right
        x.right = node

        x.color = node.color
        node.color = RED

        return x

    """
    *************************插入操作*******************************
    """
    # 时间复杂度：O(logn)
    def add(self, e):
        self.root = self.addR(self.root, e)
        # 保持根节点为黑色
        self.root.color = BLACK

    # 将节点 e 插入到以 node 为根节点的子树当中
    # 并返回插入节点后的二叉查找树的根节点
    def addR(self, node, e):
        # 1. 递归终止条件
        if not node:
            self.size += 1
            return TreeNode(e)

        # 2. 递归调用
        # bug 修复：插入的时候只考虑不相等的元素，相等的元素不做任何插入动作
        if self.__comp(e, node.data) < 0:
            node.left = self.addR(node.left, e)
        elif self.__comp(e, node.data) > 0:
            node.right = self.addR(node.right, e)
        else:
            return node

        # 维护以 node 为根节点的子树的黑平衡
        if self.isRED(node.right) and not self.isRED(node.left):
            node = self.leftRotate(node)
        if self.isRED(node.left) and self.isRED(node.left.left):
            node = self.rightRotate(node)
        if self.isRED(node.left) and self.isRED(node.right):
            self.flipColors(node)

        return node

    """
    *************************修改操作*******************************
    // set 方法会破坏二叉查找树的性质
    public void set(E src, E target) {
        if (contains(target)) return;
        TreeNode srcNode = find(src);
        srcNode.data = target;
    }
    """

    """
    *************************查询操作*******************************
    """

    def contains(self, target):
        node = self.find(target)
        if not node:
            return False
        return True

    # 时间复杂度：O(logn)
    def find(self, target):
        return self.findR(self.root, target)

    def findR(self, node, target):
        if not node:
            return None
        if self.__comp(target, node.data) == 0:
            return node
        elif self.__comp(target, node.data) < 0:
            return self.findR(node.left, target)
        else:
            return self.findR(node.right, target)

    # 中序遍历
    def inOrder(self):
        res = []

        def inOrderR(node):
            if not node:
                return []
            inOrderR(node.left)
            res.append(node.data)
            inOrderR(node.right)

        inOrderR(self.root)
        return res

    # 时间复杂度：O(logn)
    def minValue(self):
        if not self.root:
            raise Exception("tree is null")
        return self.minValueR(self.root).data

    def minValueR(self, node):
        if not node.left:
            return node
        return self.minValueR(node.left)

    # 时间复杂度：O(logn)
    def maxValue(self):
        if not self.root:
            raise Exception("tree is null")
        return self.maxValueR(self.root).data

    def maxValueR(self, node):
        if not node.right:
            return node
        return self.maxValueR(node.right)

    """
    *************************删除操作*******************************
    """
    # 时间复杂度：O(logn)
    def removeMin(self):
        if not self.root:
            raise Exception("tree is null")
        res = self.minValue()
        self.root = self.removeMinR(self.root)
        return res

    # 删除以  node 为根节点的子树的最小节点
    # 并返回删除完最小节点的子树的根节点
    def removeMinR(self, node):
        if not node.left:
            right_node = node.right
            node.right = None
            self.size -= 1
            return right_node
        left_node = self.removeMinR(node.left)
        node.left = left_node
        return node

    # 时间复杂度：O(logn)
    def removeMax(self):
        if not self.root:
            raise Exception("tree is null")
        res = self.maxValue()
        self.root = self.removeMinR(self.root)
        return res

    def removeMaxR(self, node):
        if not node.right:
            left_node = node.left
            node.left = None
            self.size -= 1
            return left_node
        right_node = self.removeMinR(node.right)
        node.right = right_node
        return node

    # 时间复杂度：O(logn)
    def remove(self, e):
        self.root = self.removeR(self.root, e)

    def removeR(self, node, e):
        if not node:
            return None

        if self.__comp(e, node.data) < 0:
            node.left = self.removeR(node.left, e)
            return node
        elif self.__comp(e, node.data) > 0:
            node.right = self.removeR(node.right, e)
            return node
        else:
            # 要删除的节点就是 node
            if not node.left:
                right_node = node.right
                node.right = None
                self.size -= 1
                return right_node

            if not node.right:
                left_node = node.left
                node.left = None
                self.size -= 1
                return left_node

            # node 的 left 和 right 都不为空
            successor = self.minValueR(node.right)
            successor.right = self.removeMinR(node.right)
            successor.left = node.left

            node.left = None
            node.right = None
            # bug 修复：这里不用修改 size 了，因为在上面的 removeMin 已经修改过了
            # self.size -= 1
            return successor