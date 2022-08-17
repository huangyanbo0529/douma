
class ArrayList:

    def __init__(self):
        """
        Python3 中没有显示的静态数组，通过下面创建的数组是动态数组：
            arr = []
        或者：
            arr = list()

        以上都是创建的动态数组，所以我们不需要考虑扩容，它自己会处理扩容
        """
        self.data = []

    def isEmpty(self):
        return len(self.data) == 0

    def getSize(self):
        return len(self.data)

    """
    **** 新增操作 ****
    向指定索引位置添加一个新元素
    时间复杂度 O(n)
    """
    def add(self, index, e):
        # Python3 数组会自动扩容
        # 如果 index < 0 的话，那么相当于 addFirst
        # 如果 index >= len(self.data) 的话，那么相当于 addLast
        self.data.insert(index, e)

    # 时间复杂度 O(n)
    def addFirst(self, e):
        self.data.insert(0, e)

    # 时间复杂度 O(1)
    def addLast(self, e):
        self.data.append(e)

    """
    **** 查询操作 ****
    获取 index 索引位置的元素
    时间复杂度 O(1)
    """
    def get(self, index):
        if index < 0 or index >= self.getSize():
            raise Exception("get failed, require index >= 0 && index < size")
        return self.data[index]

    def getLast(self):
        return self.get(self.getSize() - 1)

    def getFirst(self):
        return self.get(0)

    # 时间复杂度 O(n)
    def contains(self, e):
        for num in self.data:
            if e == num:
                return True
        return False

    # 查找数组元素 e 所在的索引，如果不存在的元素 e，则返回 -1
    # 时间复杂度 O(n)
    def find(self, e):
        for i in range(self.getSize()):
            if self.data[i] == e:
                return i
        return -1

    """
    **** 修改操作 ****
    将 index 索引位置的元素修改为新元素 e
    时间复杂度 O(1)
    """
    def set(self, index, e):
        if index < 0 or index >= self.getSize():
            raise Exception("set failed, require index >= 0 && index < size")
        self.data[index] = e

    """
    **** 删除操作 ****
    删除指定索引位置的元素，并返回删除的元素
    时间复杂度 O(n)
    """
    def remove(self, index):
        if index < 0 or index >= self.getSize():
            raise Exception("remove failed, require index >= 0 && index < size")
        res = self.data[index]
        # 移动数据，时间复杂度 O(n)
        for i in range(index + 1, self.getSize()):
            self.data[i - 1] = self.data[i]
        # 删除数组的最后一个元素
        self.data.pop()
        return res

    # 删除第一个元素 时间复杂度 O(n)
    def removeFirst(self):
        return self.remove(0)

    # 删除最后一个元素 时间复杂度 O(1)
    def removeLast(self):
        return self.remove(self.getSize() - 1)

    # 删除指定元素, 时间复杂度 O(n)
    def removeElement(self, e):
        index = self.find(e)
        if index != -1:
            # Python 中的数组的 remove 方法是删除第一次出现的元素
            self.data.remove(e)

    def toString(self):
        res = "Array: size = {}\n".format(self.getSize())
        res += "["
        for i in range(self.getSize()):
            res += str(self.data[i])
            if i != self.getSize() - 1:
                res += ","
        res += "]"
        return res

