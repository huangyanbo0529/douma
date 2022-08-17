from collections import deque

from tree.btree.TreeNode import TreeNode


def preOrder(root: TreeNode):
    """
    前序遍历
    时间复杂度：O(n), n 表示二叉树节点个数
    空间复杂度：O(n)
    """
    if root is None:
        return []
    res, stack = [], []
    stack.append(root)
    while len(stack):
        curr = stack.pop()
        res.append(curr.data)
        if curr.right:
            stack.append(curr.right)
        if curr.left:
            stack.append(curr.left)
    return res


def preOrderR(root: TreeNode):
    """
    前序遍历（递归）
    时间复杂度：O(n), n 表示二叉树节点个数
    空间复杂度：O(n)
    """
    res = []

    def preOrder(node):
        if node is None:
            return
        res.append(node.data)
        preOrder(node.left)
        preOrder(node.right)

    preOrder(root)
    return res


def inOrder(root: TreeNode):
    """
    中序遍历
    时间复杂度：O(n), n 表示二叉树节点个数
    空间复杂度：O(n)
    """
    if root is None:
        return []
    res, stack = [], []
    curr = root
    while curr or len(stack):
        while curr:
            stack.append(curr)
            curr = curr.left
        node = stack.pop()
        res.append(node.data)
        curr = node.right
    return res


def inOrderR(root: TreeNode):
    """
    中序遍历（递归）
    时间复杂度：O(n), n 表示二叉树节点个数
    空间复杂度：O(n)
    """
    res = []

    def inOrder(node):
        if node is None:
            return
        inOrder(node.left)
        res.append(node.data)
        inOrder(node.right)

    inOrder(root)
    return res


def postOrder(root: TreeNode):
    """
    后序遍历
    时间复杂度：O(n), n 表示二叉树节点个数
    空间复杂度：O(n)
    """
    if root is None:
        return []
    res, stack = [], []
    stack.append(root)
    while len(stack):
        curr = stack.pop()
        res.append(curr.data)
        if curr.left:
            stack.append(curr.left)
        if curr.right:
            stack.append(curr.right)
    res.reverse()
    return res


def postOrderR(root: TreeNode):
    """
    后序遍历（递归）
    时间复杂度：O(n), n 表示二叉树节点个数
    空间复杂度：O(n)
    """
    res = []

    def postOrder(node):
        if node is None:
            return
        postOrder(node.left)
        postOrder(node.right)
        res.append(node.data)

    postOrder(root)
    return res


def levelOrder(root: TreeNode):
    """
    层序遍历
    时间复杂度：O(n), n 表示二叉树节点个数
    空间复杂度：O(n)
    :param root:
    :return:
    """
    if root is None:
        return []
    # Python 中可以使用双端队列 deque 来实现单端队列 queue 的功能
    res, queue = [], deque()
    queue.append(root)
    while len(queue):
        # 每轮循环遍历处理一个节点
        curr = queue.popleft()
        res.append(curr.data)
        # 将遍历处理的节点的左右子节点入队，等到后序的处理
        if curr.left:
            queue.append(curr.left)
        if curr.right:
            queue.append(curr.right)
    return res


def levelOrder_2(root: TreeNode):
    """
    层序遍历
    时间复杂度：O(n), n 表示二叉树节点个数
    空间复杂度：O(n)
    :param root:
    :return:
    """
    if root is None:
        return []
    # Python 中可以使用双端队列 deque 来实现单端队列 queue 的功能
    res, queue = [], deque()
    queue.append(root)
    while len(queue):
        # 每轮循环遍历处理一层的节点
        size, level_nodes = len(queue), []
        for i in range(size):
            curr = queue.popleft()
            level_nodes.append(curr.data)
            # 将遍历处理的节点的左右子节点入队，等到后序的处理
            if curr.left:
                queue.append(curr.left)
            if curr.right:
                queue.append(curr.right)
        res.append(level_nodes)

    return res


if __name__ == '__main__':
    root = TreeNode(23)
    node1 = TreeNode(34)
    node2 = TreeNode(21)
    node3 = TreeNode(99)
    node4 = TreeNode(77)
    node5 = TreeNode(90)
    node6 = TreeNode(45)
    node7 = TreeNode(60)

    root.left = node1
    root.right = node2
    node1.left = node3
    node3.left = node4
    node3.right = node5
    node2.left = node6
    node2.right = node7

    print(preOrder(root))
    print(preOrderR(root))
    print(inOrder(root))
    print(inOrderR(root))
    print(postOrder(root))
    print(postOrderR(root))
    print(levelOrder(root))
    print(levelOrder_2(root))
