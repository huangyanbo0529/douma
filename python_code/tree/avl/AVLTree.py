# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class TreeNode:
    def __init__(self, data, left=None, right=None, height=1):
        self.data = data
        self.left = left
        self.right = right
        self.height = height


class AVLTree:
    def __init__(self, __comp):
        self.root = None
        self.size = 0
        self.__comp = __comp

    def getSize(self):
        return self.size

    def isEmpty(self):
        return self.size == 0

    def getHeight(self, node):
        if not node:
            return 0
        return node.height

    def getBalanceFactor(self, node):
        if not node:
            return 0
        # 平衡因子等于左右子节点的高度差
        return self.getHeight(node.left) - self.getHeight(node.right)

    # 判断一棵二叉树是否是二叉查找树
    def isBST(self):
        # 先中序遍历二叉查找树，得到遍历的结果列表
        res = self.inOrder()
        if len(res) <= 1:
            return True
        # 然后判断结果列表是否是增序排列的
        for i in range(1, len(res)):
            if self.__comp(res[i], res[i - 1]) < 0:
                return False
        return True

    # 判断一棵树是否平衡
    def isBalanced(self):
        return self.isBalancedR(self.root)

    def isBalancedR(self, node):
        if not node:
            return True
        balance_factor = self.getBalanceFactor(node)
        if abs(balance_factor) > 1:
            return False
        return self.isBalancedR(node.left) and self.isBalancedR(node.right)

    """
     对节点 y 进行向右旋转操作，返回旋转后新的根节点 x
            y                                    x
           / \                                 /   \
          x   T4        向右旋转 (y)          z       y
         / \          --------------->      / \     / \
        z   T3                            T1   T2 T3   T4
       / \
     T1   T2
    """

    def rightRotate(self, y):
        x = y.left
        t3 = x.right
        # 右旋转
        x.right = y
        y.left = t3
        # 更新 x 和 y 的高度
        # bug 修复，必须先要计算 y 节点的高度，然后才计算 x 节点的高度
        # 原因：上面的 x.left = y ，说明 y 是 x 的子节点，需要先计算子节点的高度，才能计算父节点高度
        y.height = max(self.getHeight(y.left), self.getHeight(y.right)) + 1
        x.height = max(self.getHeight(x.left), self.getHeight(x.right)) + 1

        # 返回调整之后的根节点
        return x

    """
     对节点y进行向左旋转操作，返回旋转后新的根节点x
        y                             x
      /  \                          /   \
     T4   x      向左旋转 (y)       y     z
         / \   - - - - - - - ->   / \   / \
       T3  z                     T4 T3 T1 T2
          / \
         T1 T2
    """

    def leftRotate(self, y):
        x = y.right
        t3 = x.left
        # 左旋转
        x.left = y
        y.right = t3
        # 更新 x 和 y 的高度
        # bug 修复，必须先要计算 y 节点的高度，然后才计算 x 节点的高度
        # 原因：上面的 x.left = y ，说明 y 是 x 的子节点，需要先计算子节点的高度，才能计算父节点高度
        y.height = max(self.getHeight(y.left), self.getHeight(y.right)) + 1
        x.height = max(self.getHeight(x.left), self.getHeight(x.right)) + 1

        # 返回调整之后的根节点
        return x

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

        # 更新父亲节点的高度值
        # 父亲节点的高度值等于左右子节点最大的高度值再加上 1
        node.height = max(self.getHeight(node.left), self.getHeight(node.right)) + 1
        # 计算每个父亲节点的平衡因子
        balance_factor = self.getBalanceFactor(node)
        # LL
        if balance_factor > 1 and self.getBalanceFactor(node.left) >= 0:
            # 处理左边不平衡，进行右旋转
            return self.rightRotate(node)
        # RR
        if balance_factor < -1 and self.getBalanceFactor(node.right) <= 0:
            # 处理右边不平衡，进行左旋转
            return self.leftRotate(node)
        # LR
        if balance_factor > 1 and self.getBalanceFactor(node.left) < 0:
            # 先将 node.left 进行左旋，转成 LL
            node.left = self.leftRotate(node.left)
            # 然后对 node 进行右旋
            return self.rightRotate(node)
        # RL
        if balance_factor < -1 and self.getBalanceFactor(node.right) > 0:
            # 先将 node.right 进行右旋，转成 RR
            node.right = self.rightRotate(node.right)
            # 再将 node 进行左旋
            return self.leftRotate(node)

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
            retNode = node
        elif self.__comp(e, node.data) > 0:
            node.right = self.removeR(node.right, e)
            retNode = node
        else:
            # 要删除的节点就是 node
            if not node.left:
                right_node = node.right
                node.right = None
                self.size -= 1
                # 注意：这里其实可以直接返回 retNode 的
                # 因为右子树是已经平衡了的，不需要再调整了
                # 这里不直接返回，是为了统一对 retNode 的处理
                retNode = right_node
            elif not node.right:
                left_node = node.left
                node.left = None
                self.size -= 1
                # 注意：这里其实可以直接返回 retNode 的
                # 因为左子树是已经平衡了的，不需要再调整了
                # 这里不直接返回，是为了统一对 retNode 的处理
                retNode = left_node
            else:
                # node 的 left 和 right 都不为空
                successor = self.minValueR(node.right)
                successor.right = self.removeMinR(node.right)
                successor.left = node.left

                node.left = None
                node.right = None
                # bug 修复：这里不用修改 size 了，因为在上面的 removeMin 已经修改过了
                # self.size -= 1
                retNode = successor

            # bug 修复：需要对 retNode 判空
            if not retNode:
                return None

        # 更新父亲节点的高度值
        # 父亲节点的高度值等于左右子节点最大的高度值再加上 1
        retNode.height = max(self.getHeight(retNode.left),
                             self.getHeight(retNode.right)) + 1
        # 计算每个父亲节点的平衡因子
        balance_factor = self.getBalanceFactor(retNode)
        # LL
        if balance_factor > 1 and self.getBalanceFactor(retNode.left) >= 0:
            # 处理左边不平衡，进行右旋转
            return self.rightRotate(retNode)
        # RR
        if balance_factor < -1 and self.getBalanceFactor(retNode.right) <= 0:
            # 处理右边不平衡，进行左旋转
            return self.leftRotate(retNode)
        # LR
        if balance_factor > 1 and self.getBalanceFactor(retNode.left) < 0:
            # 先将 node.left 进行左旋，转成 LL
            retNode.left = self.leftRotate(retNode.left)
            # 然后对 node 进行右旋
            return self.rightRotate(retNode)
        # RL
        if balance_factor < -1 and self.getBalanceFactor(retNode.right) > 0:
            # 先将 node.right 进行右旋，转成 RR
            retNode.right = self.rightRotate(retNode.right)
            # 再将 node 进行左旋
            return self.leftRotate(retNode)

        return retNode
