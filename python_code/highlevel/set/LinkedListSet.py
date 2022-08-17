# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
from line.linkedlist.LinkedList import LinkedList


class LinkedListSet:
    def __init__(self):
        self.data = LinkedList()

    def size(self):
        return self.data.getSize()

    def isEmpty(self):
        return self.data.isEmpty()

    def add(self, e):
        if not self.data.contains(e):
            self.data.addFirst(e)

    def remove(self, e):
        if self.data.contains(e):
            self.data.removeElement(e)

    def contains(self, e):
        return self.data.contains(e)

    def toString(self):
        return "LinkedListSet[ data = {} ]".format(self.data.toString())


if __name__ == '__main__':
    set1 = LinkedListSet()
    set1.add(2)
    set1.add(4)
    set1.add(1)

    print(set1.toString())

    set1.add(2)
    print(set1.toString())

    print(set1.contains(4))

    set1.remove(1)
    print(set1.toString())
