# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
from tree.btree.TreeNode import TreeNode


class BSTR:
    def __init__(self, __comp):
        self.root = None
        self.size = 0
        self.__comp = __comp

    def getSize(self):
        return self.size

    def isEmpty(self):
        return self.size == 0

    """
    *************************插入操作*******************************
    """
    # 时间复杂度：O(logn)
    def add(self, e):
        self.root = self.addR(self.root, e)

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
        left_root = self.removeMinR(node.left)
        node.left = left_root
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
        right_root = self.removeMinR(node.right)
        node.right = right_root
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