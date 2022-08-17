# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
import random
import time

from line.algo.sort import BubbleSorter, SelectionSorter, InsertionSorter, ShellSorter


def gen_data(n):
    data = [0] * n
    for i in range(n):
        data[i] = random.randint(0, 1 << 31)
    return data


def time_1(sort_type, data):
    start = time.time()

    if "bubble" == sort_type:
        BubbleSorter.sort(data)
    elif "selection" == sort_type:
        SelectionSorter.sort(data)
    elif "insertion" == sort_type:
        InsertionSorter.sort(data)
    elif "insertion1" == sort_type:
        InsertionSorter.sort1(data)
    elif "shell" == sort_type:
        ShellSorter.sort(data)

    return time.time() - start


def many_times_sort(sort_type, n, k):
    total_time = 0
    for i in range(k):
        total_time += time_1(sort_type, gen_data(n))
    return  total_time


t1 = many_times_sort("bubble", 1000, 100)
t2 = many_times_sort("selection", 1000, 100)
# t1 > t2
print(t1 / t2)

t3 = many_times_sort("insertion1", 1000, 100)
# t2 > t3
print(t2 / t3)

t4 = many_times_sort("insertion", 1000, 100)
# t3 > t4
print(t3 / t4)

t5 = many_times_sort("shell", 1000, 100)
# 结论：插入排序性能最好，其次是选择排序，最后是冒泡排序
print(t3 / t5)