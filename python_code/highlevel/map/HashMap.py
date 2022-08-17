# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class Node:
    def __init__(self, key=None, value=None, next=None):
        self.key = key
        self.value = value
        self.next = next

    def toString(self):
        return str(self.key) + "->" + str(self.value)


class HashMap:
    def __init__(self, __hash, __equal, initCapacity=25, loadFactor=0.75):
        self.data = [None] * initCapacity
        self.__size = 0
        self.__hash = __hash
        self.__equal = __equal
        self.loadFactor = loadFactor

    # 计算一个 key 对应的索引值
    def hash(self, key, length):
        return abs(self.__hash(key)) % length

    def size(self):
        return self.__size

    def isEmpty(self):
        return self.__size == 0

    def add(self, key, value):
        index = self.hash(key, len(self.data))
        curr = self.getNode(key, index)
        if not curr:
            self.data[index] = Node(key, value, self.data[index])
            self.__size += 1
            if self.__size >= len(self.data) * self.loadFactor:
                self.resize(2 * len(self.data))
        else:
            curr.value = value

    def getNode(self, key, index):
        curr = self.data[index]
        while curr:
            if self.__equal(key, curr.key):
                break
            curr = curr.next
        return curr

    def resize(self, new_capacity):
        new_data = [None] * new_capacity
        for i in range(len(self.data)):
            curr = self.data[i]
            while curr:
                key = curr.key
                new_index = self.hash(key, new_capacity)
                head = new_data[new_index]
                new_data[new_index] = Node(key, curr.value)
                if head:
                    new_data[new_index].next = head
                curr = curr.next
        self.data = new_data

    def remove(self, key):
        index = self.hash(key, len(self.data))
        if not self.data[index]:
            return None
        prev, curr = None, self.data[index]
        while curr:
            if self.__equal(key, curr.key):
                if not prev:
                    self.data[index] = curr.next
                else:
                    prev.next = curr.next
                curr.next = None
                self.__size -= 1
                return curr.value
            prev = curr
            curr = curr.next
        return None

    def set(self, key, new_value):
        index = self.hash(key, len(self.data))
        curr = self.getNode(key, index)
        if curr:
            curr.value = new_value
        else:
            raise Exception("没有对应的 key ：{}".format(key))

    def get(self, key):
        index = self.hash(key, len(self.data))
        node = self.getNode(key, index)
        return node.value if node else None

    def containsKey(self, key):
        index = self.hash(key, len(self.data))
        node = self.getNode(key, index)
        return node
