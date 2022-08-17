# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class TreeNode:
    def __init__(self, key, value, left=None, right=None):
        self.key = key
        self.value = value
        self.left = left
        self.right = right


class BSTMap:
    def __init__(self, __comp):
        self.root = None
        self.__size = 0
        self.__comp = __comp

    def size(self):
        return self.__size

    def isEmpty(self):
        return self.__size == 0

    # 时间复杂度：O(logn)
    def add(self, key, value):
        self.root = self.addR(self.root, key, value)

    # 将节点 e 插入到以 node 为根节点的子树当中
    # 并返回插入节点后的二叉查找树的根节点
    def addR(self, node, key, value):
        # 1. 递归终止条件
        if not node:
            self.size += 1
            return TreeNode(key, value)

        # 2. 递归调用
        # bug 修复：插入的时候只考虑不相等的元素，相等的元素不做任何插入动作
        if self.__comp(key, node.key) < 0:
            node.left = self.addR(node.left, key, value)
        elif self.__comp(key, node.key) > 0:
            node.right = self.addR(node.right, key, value)

        return node

    # 时间复杂度：O(logn)
    def remove(self, key):
        node = self.getR(self.root, key)
        if not node:
            return None
        self.root = self.removeR(self.root, key)
        return node.value

    def removeR(self, node, key):
        if not node:
            return None

        if self.__comp(key, node.key) < 0:
            node.left = self.removeR(node.left, key)
            return node
        elif self.__comp(key, node.key) > 0:
            node.right = self.removeR(node.right, key)
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

    def minValueR(self, node):
        if not node.left:
            return node
        return self.minValueR(node.left)

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

    # TODO : 这样直接修改数据的话，会影响 BST 的性质
    def set(self, key, new_value):
        node = self.getR(self.root, key)
        if not node:
            raise Exception("没有对应的 key ：{}".format(key))
        node.value = new_value

    # 时间复杂度：O(logn)
    def get(self, key):
        node = self.getR(self.root, key)
        return node.value if node else None

    def getR(self, node, key):
        if not node:
            return None
        if self.__comp(key, node.key) == 0:
            return node
        elif self.__comp(key, node.key) < 0:
            return self.findR(node.left, key)
        else:
            return self.findR(node.right, key)

    def contains(self, key):
        node = self.getR(self.root, key)
        return node

