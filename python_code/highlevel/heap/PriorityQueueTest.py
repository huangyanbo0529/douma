# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
import heapq

from highlevel.heap.PriorityQueue import PriorityQueue

if __name__ == '__main__':
    pq = PriorityQueue(lambda a, b: a - b)
    pq.enqueue(13)
    pq.enqueue(10)
    pq.enqueue(56)

    print(pq.dequeue())  # 56
    print(pq.getFront())  # 13

    # Python 中内置的优先队列
    # 初始化一个数组，用于堆存储数据
    pq = []
    # 这里使用 heapq 来实现堆的功能，默认是小顶堆
    # 将数据 push 到堆中
    heapq.heappush(pq, 13)
    heapq.heappush(pq, 10)
    heapq.heappush(pq, 56)

    # 弹出堆顶元素
    print(heapq.heappop(pq))  # 10
    print(heapq.heappop(pq))  # 13

    # 我们也可以将一个已经存在元素的数据进行堆化
    pq = [10, 20, 5, 2, 22]
    heapq.heapify(pq)
    print(heapq.heappop(pq))  # 2

    # heapq 默认的是小顶堆，如果你想实现大顶堆的话，可以使用负数作为比较
    pq = [10, 20, 5, 2, 22]
    # 先将所有元素变成负数
    tmp = [-x for x in pq]
    heapq.heapify(tmp)
    # 别忘了，需要加上 - 号才能得到之前的原值
    print(-heapq.heappop(tmp))  # 得到 22

    # 当元素是一个二元组的时候，堆中比较是按照第一个元素比较的
    pq = []
    heapq.heappush(pq, (1, 30))
    heapq.heappush(pq, (0, 12))
    heapq.heappush(pq, (10, 40))

    print(heapq.heappop(pq))  # 得到的是 (0, 12)
