# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class Item:
    def __init__(self, data):
        self.data = data
        self.is_deleted = False

    def toString(self):
        return str(self.data)


class HashSet:
    def __init__(self, __hash, __equal):
        self.items = [None] * 10
        self.__size = 0
        self.__hash = __hash
        self.__equal = __equal
        # 用于记录有多少标记删除的元素
        self.delete_count = 0
        self.loadFactor = 0.75

    def hash(self, e, length):
        return abs(self.__hash(e)) % length

    def size(self):
        return self.__size

    def isEmpty(self):
        return self.__size == 0

    def add(self, e):
        index = self.hash(e, len(self.items))
        # add_index 表示元素 e 需要插入的索引位置
        # is_first 用于辅助找到元素 e 插入的位置
        add_index, is_first = index, True

        # bug 修复：add 前先判断是否存在元素 e
        while self.items[index] and self.__equal(e, self.items[index].data):
            # 找到第一个等于 null 或者删除的元素，并记录赋值给 addIndex
            if (not self.items[index] or self.items[index].is_deleted) and is_first:
                add_index, is_first = index, False
            index += 1
            index = index % len(self.items)

        # 说明已经存在 e，则直接返回
        if self.items[index] and not self.items[index].is_deleted:
            return

        # 这个时候的 addIndex 对应的元素要么是 null ，要么是已经删除的元素
        # 如果 addIndex 对应的元素是标记为删除的元素，那么直接被覆盖了，标记为删除的元素个数减少 1
        if self.items[add_index] and self.items[add_index].is_deleted:
            self.delete_count -= 1
        self.items[add_index] = Item(e)
        self.__size += 1
        if self.__size >= len(self.items) * self.loadFactor:
            self.resize(2 * len(self.items))

    def resize(self, newCapacity):
        new_data = [None] * newCapacity
        for i in range(len(self.items)):
            if self.items[i] and not self.items[i].is_deleted:
                new_index = self.hash(self.items[i], newCapacity)
                new_data[new_index] = self.items[i]
        self.items = new_data
        # 所有标记为删除的元素都清理掉了
        self.delete_count = 0

    def remove(self, e):
        index = self.hash(e, len(self.items))
        # 找到等于 e 或者元素为 null 的索引
        while self.items[index] and not self.__equal(e, self.items[index].data):
            index += 1
            index = index % len(self.items)
        if self.items[index]:
            self.items[index].is_deleted = True
            self.__size -= 1
            self.delete_count += 1
        # 如果标记为删除的元素太多的话，我们进行 resize，清除标记为删除的元素
        # TODO：这里可能会产生时间复杂度震荡
        if self.delete_count + self.__size >= len(self.items) * self.loadFactor:
            self.resize(len(self.items))

    def contains(self, e):
        index = self.hash(e, len(self.items))
        # 找到等于 e 或者元素为 null 的索引
        while self.items[index] and not self.__equal(e, self.items[index].data):
            index += 1
            index = index % len(self.items)
        return self.items[index] and not self.items[index].is_deleted

    def toString(self):
        res = ""
        for data in self.items:
            if data and not data.is_deleted:
                res += data.toString() + ", "
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
