# 抖码算法，让算法学习变得简单有趣
# 作者：老汤

# 时间复杂度：O(nlogn)
# 空间复杂度：O(n)
from highlevel.heap.MaxHeap import MaxHeap


def sort(data):
    # 1. 建堆，堆化 O(n)
    max_heap = MaxHeap(lambda a, b: a - b, data)

    # 2. 排序
    i, tmp = len(data) - 1, [0] * len(data)
    # O(nlogn)
    while not max_heap.isEmpty():
        tmp[i] = max_heap.removeMax()
        i -= 1

    # 3. 拷贝
    for i in range(len(data)):
        data[i] = tmp[i]


if __name__ == '__main__':
    data = [15, 17, 19, 13, 22, 16, 28, 30, 42, 66]
    sort(data)
    print(data)