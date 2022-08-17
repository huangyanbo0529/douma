# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
from tree.bst.BST import BST


class BSTSet:
    def __init__(self, __comp):
        self.bst = BST(__comp)

    def size(self):
        return self.bst.getSize()

    def isEmpty(self):
        return self.bst.isEmpty()

    def add(self, e):
        self.bst.add(e)

    def remove(self, e):
        self.bst.remove(e)

    def contains(self, e):
        return self.bst.contains(e)

    def toString(self):
        return "BSTSet[ data = {} ]".format(self.bst.inOrder())


if __name__ == '__main__':
    set1 = BSTSet(lambda a, b: a - b)
    set1.add(2)
    set1.add(4)
    set1.add(1)

    print(set1.toString())

    set1.add(2)
    print(set1.toString())

    print(set1.contains(4))

    set1.remove(1)
    print(set1.toString())
