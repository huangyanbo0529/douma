# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class HashSet:
    def __init__(self, __hash):
        self.data = [None] * 10
        self.__size = 0
        self.__hash = __hash

    def hash(self, e, length):
        return abs(self.__hash(e)) % length

    def size(self):
        return self.__size

    def isEmpty(self):
        return self.__size == 0

    def add(self, e):
        index = self.hash(e, len(self.data))
        # bug 修复：为 None 的时候才插入
        if not self.data[index]:
            self.data[index] = e
            self.__size += 1
            if self.__size == len(self.data):
                self.resize(2 * len(self.data))

    def resize(self, newCapacity):
        new_data = [None] * newCapacity
        for i in range(len(self.data)):
            if self.data[i]:
                new_index = self.hash(self.data[i], newCapacity)
                new_data[new_index] = self.data[i]
        self.data = new_data

    def remove(self, e):
        index = self.hash(e, len(self.data))
        # bug 修复：在删除某个元素之前，先判断这个元素是否存在
        # 存在的话才删除
        if self.data[index]:
            self.data[index] = None
            self.__size -= 1

    def contains(self, e):
        index = self.hash(e, len(self.data))
        return self.data[index]

    def toString(self):
        return "HashSet[ data = {} ]".format(self.data)


if __name__ == '__main__':
    set1 = HashSet(lambda a: a)
    set1.add(2)
    set1.add(4)
    set1.add(1)

    print(set1.toString())

    set1.add(2)
    print(set1.toString())

    print(set1.contains(4))

    set1.remove(1)
    print(set1.toString())
