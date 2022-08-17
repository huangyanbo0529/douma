class LoopQueue:

    def __init__(self, capacity=20):
        self.data = [0] * capacity
        self.head = self.tail = 0
        self.size = 0

    def getCapacity(self):
        return len(self.data) - 1

    def getSize(self):
        return self.size

    def enqueue(self, e):
        # 这里也可以使用 size 来判断队列是否满了，参考 issue ：https://gitee.com/douma_edu/douma-algo/issues/I4WGCE
        if (self.tail + 1) % len(self.data) == self.head:
            # 队列满了，扩容
            self.resize(self.getCapacity() * 2)
        self.data[self.tail] = e
        self.size += 1
        self.tail = (self.tail + 1) % len(self.data)

    def dequeue(self):
        if self.isEmpty():
            raise Exception("dequeue error, No Element for dequeue")
        res = self.data[self.head]
        self.data[self.head] = None
        self.size -= 1
        self.head = (self.head + 1) % len(self.data)
        if self.size == self.getCapacity() // 4:
            self.resize(self.getCapacity() // 2)
        return res

    def resize(self, new_capacity):
        new_data = [None] * (new_capacity + 1)
        for i in range(self.size):
            new_data[i] = self.data[(i + self.head) % len(self.data)]
        self.data = new_data
        self.head = 0
        self.tail = self.size

    def isEmpty(self):
        # 这里也可以使用 size 来判断队列是否空，参考 issue ：https://gitee.com/douma_edu/douma-algo/issues/I4WGCE
        return self.head == self.tail

    def getFront(self):
        if self.isEmpty():
            raise Exception("getFront error, No Element for dequeue")
        return self.data[self.head]

    def toString(self):
        res = "Queue：size = {}, capacity = {}\n".format(self.size, self.getCapacity())
        res += " 队首 ["
        i = self.head
        while i != self.tail:
            res += str(self.data[i])
            if (i + 1) % len(self.data) != self.tail:
                res += ","
            i = (i + 1) % len(self.data)
        res += "]"
        return res