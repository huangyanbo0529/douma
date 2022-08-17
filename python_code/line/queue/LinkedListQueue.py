from line.linkedlist.LinkedList import LinkedList


class LinkedListQueue:
    def __init__(self):
        self.data = LinkedList()

    def getSize(self):
        return self.data.getSize()

    def isEmpty(self):
        return self.data.isEmpty()

    # 时间复杂度 O(n)
    def enqueue(self, e):
        self.data.addLast()

    # 时间复杂度 O(1)
    def dequeue(self):
        if self.isEmpty():
            raise Exception("queue is empty")
        return self.data.removeFirst()

    def getFront(self):
        if self.isEmpty():
            raise Exception("queue is empty")
        return self.data.getFirst()

    def toString(self):
        res = "Queue：队首 ["
        for i in range(self.getSize()):
            res += str(self.data.get(i))
            if i != self.data.getSize() - 1:
                res += ", "
        res += "]"
        return res
