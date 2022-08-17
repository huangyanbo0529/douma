# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
import random

from highlevel.heap.MaxHeap import MaxHeap

if __name__ == '__main__':
    n = 10000
    heap = MaxHeap(lambda x, y: x - y)

    # 1. 往堆中添加 10000 个随机整数
    for i in range(n):
        heap.add(random.randint(0, 10000))

    # 2. 依次从堆中取出 10000 个整数，并依次放入到数组中
    arr = [0] * n
    for i in range(n):
        arr[i] = heap.removeMax()

    # 3. 判断先拿出来的元素是最大的，如果不是的话，则说明不符合堆的性质
    for i in range(1, n):
        if arr[i - 1] < arr[i]:
            raise Exception("Error")

    print("Test MaxHeap Succ")