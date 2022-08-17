# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class Node:
    def __init__(self, c):
        # 每个节点包含：
        # 1. 一个字符
        self.c = c
        # 2. 若干个子节点
        self.children = []
        # 标识，这个节点是否是一个单词最后一个字符
        self.isWord = False


class Trie:
    def __init__(self):
        self.root = Node('/')

    def containsChar(self, children, c):
        for i in range(len(children)):
            if children[i].c == c:
                return i
        return -1

    def add(self, word):
        curr = self.root
        for c in word:
            index = self.containsChar(curr.children, c)
            if index == -1:
                curr.children.append(Node(c))
                index = len(curr.children) - 1
            curr = curr.children[index]
        curr.isWord = True

    def contains(self, word):
        curr = self.root
        for c in word:
            index = self.containsChar(curr.children, c)
            if index == -1:
                return False
            curr = curr.children[index]
        return curr.isWord


if __name__ == '__main__':
    trie = Trie()
    trie.add("big")
    trie.add("pat")
    trie.add("bigger")
    trie.add("dog")
    trie.add("door")
    print(trie.contains("biggere"))  # False


