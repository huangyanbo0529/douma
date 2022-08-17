# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
from highlevel.heap.MaxHeap import MaxHeap


class PriorityQueue:
    def __init__(self, __comp):
        self.maxHeap = MaxHeap(__comp)

    def getSize(self):
        return self.maxHeap.size()

    def isEmpty(self):
        return self.maxHeap.isEmpty()

    def enqueue(self, e):
        self.maxHeap.add(e)

    def dequeue(self):
        return self.maxHeap.removeMax()

    def getFront(self):
        return self.maxHeap.findMax()