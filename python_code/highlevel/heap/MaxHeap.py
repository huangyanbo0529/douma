# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class MaxHeap:
    def __init__(self, __comp, data=None):
        self.__comp = __comp
        if not data:
            self.data = []
        else:
            # 这里最好是复制一份 data，这样可以避免内部修改 data 的时候影响传进来的 data
            self.data = data[:]
            for i in range(self.lastNonLeafIndex(), -1, -1):
                self.siftDown(i)

    def size(self):
        return len(self.data)

    def isEmpty(self):
        return len(self.data) == 0

    # 返回一个索引所表示的元素的左孩子节点的索引
    def leftChild(self, index):
        return index * 2 + 1

    # 返回一个索引所表示的元素的右孩子节点的索引
    def rightChild(self, index):
        return index * 2 + 2

    # 返回一个索引所表示的元素的父节点的索引
    def parent(self, index):
        if index == 0:
            raise Exception("index-0 does not have parent")
        return (index - 1) // 2

    # 返回最后一个非叶子节点的索引值
    def lastNonLeafIndex(self):
        # 后一个叶子节点的索引
        last_leaf_index = len(self.data) - 1
        # 返回最后一个叶子节点的父节点的索引值就是最后一个非叶子节点的索引
        return self.parent(last_leaf_index)

    # 将数组中索引为 index 的元素进行上浮
    def siftUp(self, index):
        e = self.data[index]
        # 循环比较并上浮，一直到节点是根节点
        while index > 0:
            parent_node = self.data[self.parent(index)]
            if self.__comp(e, parent_node) <= 0:
                break
            # 将父节点插入到子节点中
            self.data[index] = parent_node
            # 更新需要插入的元素节点的索引为它之前的父节点的索引
            index = self.parent(index)
        # 将节点插入到正确的位置上
        self.data[index] = e

    # 往大顶堆中添加一个元素
    # 时间复杂度：O(logn)
    def add(self, e):
        # 1. 先将元素插入到数组的最后
        self.data.append(e)
        # 2. 将最后一个节点 e 上浮
        self.siftUp(len(self.data) - 1)

    def findMax(self):
        if self.isEmpty():
            raise Exception("Heap is Empty")
        return self.data[0]

    def siftDown(self, index):
        e = self.data[index]
        while self.leftChild(index) < len(self.data):
            # 1. 找到节点的左右子节点值最大的那个节点
            max_node_index = self.leftChild(index)
            if self.rightChild(index) < len(self.data):
                right_node_val = self.data[self.rightChild(index)]
                left_node_val = self.data[self.leftChild(index)]
                if self.__comp(right_node_val, left_node_val) > 0:
                    max_node_index = self.rightChild(index)

            if self.__comp(e, self.data[max_node_index]) >= 0:
                break

            # 2. 将节点和最大节点的值比较，如果小的话，就需要交换
            self.data[index] = self.data[max_node_index]
            index = max_node_index
        self.data[index] = e

    # 从大顶堆中取出并删除最大值
    # 时间复杂度：O(logn)
    def removeMax(self):
        max_val = self.findMax()
        # 1. 将最后一个节点替换根节点，并删除最后一个节点
        last = self.data[len(self.data) - 1]
        self.data[0] = last

        # 2. 删除最后一个节点
        self.data.pop()

        # 3. 将新的根节点做下沉操作
        # 如果含有的元素超过 1 个了，下沉才有意义
        if len(self.data) >= 1:
            self.siftDown(0)

        return max_val
