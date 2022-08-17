from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # DFS
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root or (not root.left and not root.right):
            return root
        left, right = self.invertTree(root.left), self.invertTree(root.right)
        root.left, root.right = right, left
        return root

    # BFS
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None
        # Python 中可以使用双端队列 deque 来实现单端队列 queue 的功能
        queue = deque()
        queue.append(root)
        while len(queue):
            # 每轮循环遍历处理一个节点
            curr = queue.popleft()

            tmp = curr.left
            curr.left = curr.right
            curr.right = tmp

            # 将遍历处理的节点的左右子节点入队，等到后序的处理
            if curr.left:
                queue.append(curr.left)
            if curr.right:
                queue.append(curr.right)
        return root
