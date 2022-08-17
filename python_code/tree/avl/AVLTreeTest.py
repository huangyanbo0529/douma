# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
from tree.avl.AVLTree import AVLTree

if __name__ == '__main__':
    avl = AVLTree(lambda x, y: x - y)

    avl.add(9)
    avl.add(10)
    avl.add(11)
    avl.add(13)

    print(avl.isBST())
    print(avl.isBalanced())