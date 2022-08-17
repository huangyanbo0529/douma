# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
from highlevel.heap.MaxHeap import MaxHeap


class DataStream:
    def __init__(self, __comp):
        self.maxHeap = MaxHeap(__comp)

    # 时间复杂度：O(logn)
    def add(self, val):
        self.maxHeap.add(val)

    # O(logn)
    def removeMax(self):
        return self.maxHeap.removeMax()


if __name__ == '__main__':
    ds = DataStream(lambda a, b: a - b)
    ds.add(3)
    print(ds.removeMax())  # 打印 3
    ds.add(6)
    ds.add(5)
    print(ds.removeMax())  # 打印 6
    ds.add(2)
    ds.add(1)
    print(ds.removeMax())  # 打印 5
