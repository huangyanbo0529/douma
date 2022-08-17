# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
from tree.btree.TreeNode import TreeNode


class BST:
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
        if self.root is None:
            self.root = TreeNode(e)
        else:
            curr = self.root
            while curr:
                if self.__comp(e, curr.data) == 0:
                    return
                elif self.__comp(e, curr.data) < 0 and not curr.left:
                    curr.left = TreeNode(e)
                    self.size += 1
                    return
                elif self.__comp(e, curr.data) > 0 and not curr.right:
                    curr.right = TreeNode(e)
                    self.size += 1
                    return
                if self.__comp(e, curr.data) < 0:
                    curr = curr.left
                else:
                    curr = curr.right


    """
    *************************修改操作*******************************
    // set 方法会破坏二叉查找树的性质
    // 可以使用先删除再添加的方式，来代替 set 操作，这样的时间复杂度为 O(logn)
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
        if not self.root:
            return None
        curr = self.root
        while curr:
            if self.__comp(target, curr.data) == 0:
                return curr
            elif self.__comp(target, curr.data) < 0:
                curr = curr.left
            else:
                curr = curr.right
        return None

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
        min_node = self.root
        while min_node.left:
            # 一直往左子节点走
            min_node = min_node.left
        return min_node.data

    # 时间复杂度：O(logn)
    def maxValue(self):
        if not self.root:
            raise Exception("tree is null")
        max_node = self.root
        while max_node.right:
            # 一直往右子节点走
            max_node = max_node.right
        return max_node.data

    """
    *************************删除操作*******************************
    """
    # 时间复杂度：O(logn)
    def removeMin(self):
        if not self.root:
            raise Exception("tree is null")
        min_node, parent = self.root, None
        while min_node.left:
            parent = min_node
            min_node = min_node.left

        if not parent:
            # 删除根节点
            self.root = self.root.right
        else:
            parent.left = min_node.right

        # bug 修复：统一释放 min 节点
        min_node.right = None
        self.size -= 1
        return min_node.data

    # 时间复杂度：O(logn)
    def removeMax(self):
        if not self.root:
            raise Exception("tree is null")
        max_node, parent = self.root, None
        while max_node.right:
            parent = max_node
            max_node = max_node.right

        if not parent:
            # 删除根节点
            self.root = self.root.left
        else:
            parent.right = max_node.left

        # bug 修复：统一释放 min 节点
        max_node.left = None
        self.size -= 1
        return max_node.data

    # 时间复杂度：O(logn)
    def remove(self, e):
        if not self.root:
            return

        curr, parent = self.root, None
        # 找到要删除的节点
        while curr and self.__comp(e, curr.data) != 0:
            parent = curr
            if self.__comp(e, curr.data) < 0:
                curr = curr.left
            else:
                curr = curr.right

        # 如果没有找到需要删除的元素，则直接返回
        if not curr:
            return

        if curr.left and curr.right:
            # 1. 找到 curr 的右子树的最小值节点
            min_node, min_parent = curr.right, curr
            while min_node.left:
                min_parent = min_node
                min_node = min_node.left

            # 2. 覆盖需要删除节点的值为最小值
            curr.data = min_node.data

            # 3. 删除最小值节点
            curr, parent = min_node, min_parent

        # 删除节点是叶子节点或者仅有一个子树
        if curr.left:
            child = curr.left
            # 注意：删除的是根节点的话，也需要将当前节点的 left 置空
            curr.left = None
        elif curr.right:
            child = curr.right
            # 注意：删除的是根节点的话，也需要将当前节点的 right 置空
            curr.right = None
        else:
            child = None

        if not parent:
            self.root = child
        elif curr == parent.left:
            parent.left = child
        elif curr == parent.right:
            parent.right = child

        # bug 修复：需要维护好 size
        self.size -= 1

    def remove1(self, e):
        if not self.root:
            return

        curr, parent = self.root, None
        # 找到要删除的节点
        while curr and self.__comp(e, curr.data) != 0:
            parent = curr
            if self.__comp(e, curr.data) < 0:
                curr = curr.left
            else:
                curr = curr.right

        # 如果没有找到需要删除的元素，则直接返回
        if not curr:
            return

        # 删除叶子节点
        if not curr.left and not curr.right:
            if not parent:
                self.root = None
            elif curr == parent.left:
                parent.left = None
            elif curr == parent.right:
                parent.right = None
        elif curr.left and not curr.right:
            if not parent:
                self.root = curr.left
                # 注意：删除的是根节点的话，也需要将当前节点的 left 置空
                curr.left = None
            elif curr == parent.left:
                parent.left = curr.left
                curr.left = None
            elif curr == parent.right:
                parent.right = curr.left
                curr.left = None
        elif not curr.left and curr.right:
            if not parent:
                self.root = curr.right
                #  // 注意：删除的是根节点的话，也需要将当前节点的 right 置空
                curr.right = None
            elif curr == parent.left:
                parent.left = curr.right
                curr.right = None
            elif curr == parent.right:
                parent.right = curr.right
                curr.right = None
        elif not curr.left and not curr.right:
            # 1. 找到 curr 的右子树的最小值节点
            min_node, min_parent = curr.right, curr
            while min_node.left:
                min_parent = min_node
                min_node = min_node.left

            # 2. 覆盖需要删除节点的值为最小值
            curr.data = min_node.data

            # 3. 删除最小值节点
            # 先拿到要删除 min 节点的右子树
            right = min_node.right
            # bug 修复：这里删除 min 节点，需要区分 min 是父亲节点的右子节点还是左子节点
            # 要删除 min 节点是父亲节点的右子节点
            if min_parent.right == min_node:
                """
                比如我们要删除以下树的节点 66
                        33
                     /      \
                   22        66
                           /    \
                         35      70
                                   \
                                    99
                那么这个时候：minParent = 66，min = 70，即 min 是父亲节点的右子节点
                """
                # 将 min 的右子树挂到父亲节点的右子树中
                min_parent.right = right
            else:
                # 要删除 min 节点是父亲节点的左子节点
                """
                比如我们要删除以下树的节点 66
                        33
                     /      \
                   22        66
                           /    \
                         35      70
                               /   \
                             68     99
                               \
                                69
                那么这个时候：minParent = 70，min = 68，即 min 是父亲节点的左子节点
                """
                # 将 min 的右子树挂到父亲节点的左子树中
                min_parent.left = right
            # 删掉 min 的右子树，这样可以使得 min 节点从树中断开
            min_node.right = None

        # bug 修复：需要维护好 size
        self.size -= 1

