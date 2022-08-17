class Node:
    def __init__(self, e, next):
        self.e = e
        self.next = next

    def toString(self):
        return str(self.e)


class LinkedListQueue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def getSize(self):
        return self.size

    def isEmpty(self):
        return self.size == 0

    # 时间复杂度 O(1)
    def enqueue(self, e):
        new_node = Node(e=e)
        if not self.tail:
            self.tail = new_node
            self.head = self.tail
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.size += 1

    # 时间复杂度 O(1)
    def dequeue(self):
        if self.isEmpty():
            raise Exception("queue is empty")
        del_node = self.head
        self.head = self.head.next
        del_node.next = None
        if not self.head:
            self.tail = None
        self.size -= 1
        return del_node.e

    def getFront(self):
        if self.isEmpty():
            raise Exception("queue is empty")
        return self.head.e

    def toString(self):
        res = "Queue：队首 ["
        curr = self.head
        while curr:
            res += curr.toString() + "->"
            curr = curr.next
        res += "null]"
        return res
