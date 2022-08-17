# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
from tree.bst.BST import BST
from tree.bst.BSTR import BSTR

if __name__ == '__main__':
    # bst = BST(lambda a, b: a - b)
    bst = BSTR(lambda a, b: a - b)
    bst.add(33)
    bst.add(22)
    bst.add(66)
    bst.add(12)
    bst.add(35)
    bst.add(70)
    bst.add(34)
    bst.add(50)
    bst.add(68)
    bst.add(99)

    print(bst.inOrder())
    print(bst.contains(34))

    print(bst.minValue())
    print(bst.maxValue())

    print(bst.removeMin())
    print(bst.inOrder())

    print(bst.removeMax())
    print(bst.inOrder())

    bst.remove(66)
    print(bst.inOrder())