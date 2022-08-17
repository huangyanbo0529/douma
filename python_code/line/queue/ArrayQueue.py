class ArrayQueue:
    def __init__(self):
        self.data = []

    def getSize(self):
        return len(self.data)

    def isEmpty(self):
        return len(self.data) == 0

    # 时间复杂度 O(1)
    def enqueue(self, e):
        self.data.append(e)

    # 时间复杂度 O(n)
    def dequeue(self):
        if self.isEmpty():
            raise Exception("queue is empty")
        res = self.data[0]
        for i in range(1, len(self.data)):
            self.data[i - 1] = self.data[i]
        self.data.pop()
        return res

    def getFront(self):
        if self.isEmpty():
            raise Exception("queue is empty")
        return self.data[0]

    def toString(self):
        res = "Queue：队首 ["
        for i in range(self.getSize()):
            res += str(self.data[i])
            if i != len(self.data) - 1:
                res += ", "
        res += "]"
        return res
