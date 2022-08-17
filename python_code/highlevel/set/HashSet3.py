# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class Node:
    def __init__(self, e, next=None):
        self.e = e
        self.next = next

    def toString(self):
        return str(self.e)


class HashSet:
    def __init__(self, __hash, __equal):
        self.data = [None] * 10
        self.__size = 0
        self.__hash = __hash
        self.__equal = __equal
        self.loadFactor = 0.75

    def hash(self, e, length):
        return abs(self.__hash(e)) % length

    def size(self):
        return self.__size

    def isEmpty(self):
        return self.__size == 0

    def add(self, e):
        index = self.hash(e, len(self.data))
        if not self.data[index]:
            self.data[index] = Node(e)
        else:
            prev, curr = None, self.data[index]
            while curr:
                if self.__equal(e, curr.e):
                    return
                prev = curr
                curr = curr.next
        self.__size += 1
        if self.__size == len(self.data) * self.loadFactor:
            self.resize(2 * len(self.data))

    def resize(self, newCapacity):
        new_data = [None] * newCapacity
        for i in range(len(self.data)):
            curr = self.data[i]
            while curr:
                e = curr.e
                new_index = self.hash(e, newCapacity)
                head = new_data[new_index]
                new_data[new_index] = Node(e)
                if head:
                    new_data[new_index].next = head
                # bug 修复：curr 需要往前移动
                curr = curr.next
        self.data = new_data

    def remove(self, e):
        index = self.hash(e, len(self.data))
        if not self.data[index]:
            return
        prev, curr = None, self.data[index]
        while curr:
            if self.__equal(e, curr.e):
                if not prev:
                    # 删除头节点
                    self.data[index] = curr.next
                else:
                    prev.next = curr.next
                curr.next = None
                self.__size -= 1
                break
            prev = curr
            curr = curr.next

    def contains(self, e):
        index = self.hash(e, len(self.data))
        if not self.data[index]:
            return False
        curr = self.data[index]
        while curr:
            if self.__equal(e, curr.e):
                return True
            curr = curr.next
        return False

    def toString(self):
        res = ""
        for node in self.data:
            while node:
                res += node.toString() + "=>"
                node = node.next
            res += "\n"
        return res


if __name__ == '__main__':
    set1 = HashSet(lambda a: a, lambda a, b: a == b)
    set1.add(2)
    set1.add(4)
    set1.add(1)

    print(set1.toString())

    set1.add(2)
    print(set1.toString())

    print(set1.contains(4))

    set1.remove(1)
    print(set1.toString())
