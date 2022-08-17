from line.linkedlist.LinkedList import LinkedList


class LinkedListStack:
    def __init__(self):
        self.linkedList = LinkedList()

    def getSize(self):
        return self.linkedList.getSize()

    def isEmpty(self):
        return self.linkedList.isEmpty()

    def push(self, e):
        self.linkedList.addFirst(e)

    def pop(self):
        return self.linkedList.removeFirst()

    def peek(self):
        return self.linkedList.getFirst()