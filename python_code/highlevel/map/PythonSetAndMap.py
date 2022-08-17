# 抖码算法，让算法学习变得简单有趣
# 作者：老汤

from sortedcontainers import SortedSet, SortedDict

if __name__ == '__main__':

    """
    # 1. python 中的 Set 集合 -> 本质上是 hash set
    """
    pset = set()
    pset.add(10)     # 时间复杂度 O(1)
    pset.add(12)
    pset.add(10)
    print(pset)  # {10, 12}

    # 遍历 set
    for e in pset:
        print(e)

    # 判断 set 中是否存在某个元素
    if 10 in pset:
        print("set 中包含了 10")

    pset.remove(12)     # 时间复杂度 O(1)
    # 删除 set 中的元素
    print(pset)  # {10}

    """
    # 2. python 中的有序 set (类属于红黑树的实现的 Set)
    """
    # 需要初始化下载安装 sortedcontainers 包
    s1 = SortedSet()
    s1.add(19)  # 时间复杂度 O(logn)
    s1.add(2)
    s1.add(23)
    s1.add(2)
    s1.add(15)
    print(s1)   # SortedSet([2, 15, 19, 23])

    # 遍历 SortedSet
    for e in s1:
        print(e)

    if 2 in s1: # 时间复杂度 O(logn)
        print("set 中包含了 2")

    s1.remove(15)   # 时间复杂度 O(logn)
    print(s1)   # SortedSet([2, 19, 23])

    """
    # 3. python 中的 Map(或者说字典) -> 本质上是 hash map
    """
    pmap = dict()
    pmap[23] = 24
    pmap[99] = 12
    pmap[12] = 13
    pmap[23] = 90

    print(pmap)     # {23: 90, 99: 12, 12: 13}

    # 遍历 dict , 以下打印的是 dict 中所有的 key
    for e in pmap:
        print(e)
    # 遍历 dict , 以下打印的是 dict 中所有的 key-value 键值对
    for key, value in pmap.items():
        print(key, value)
    # 遍历 dict , 以下打印的是 dict 中所有的 key
    for e in pmap.keys():
        print(e)
    # 遍历 dict , 以下打印的是 dict 中所有的 value
    for e in pmap.values():
        print(e)

    if 23 in pmap:
        print("pmap 中包含了 23")

    # 删除字典中指定的 key
    del pmap[23]
    print(pmap)     # {99: 12, 12: 13}

    """
    # 4. python 中的有序 Map (类属于红黑树的实现的 Map)
    """
    # 需要初始化下载安装 sortedcontainers 包
    pmap = SortedDict()
    pmap[23] = 24
    pmap[99] = 12
    pmap[12] = 13
    pmap[23] = 90
    print(pmap)   # SortedDict({12: 13, 23: 90, 99: 12})

    # 遍历 SortedDict , 以下打印的是 dict 中所有的 key
    for e in pmap:
        print(e)
    # 遍历 SortedDict , 以下打印的是 dict 中所有的 key-value 键值对
    for key, value in pmap.items():
        print(key, value)
    # 遍历 SortedDict , 以下打印的是 dict 中所有的 key
    for e in pmap.keys():
        print(e)
    # 遍历 SortedDict , 以下打印的是 dict 中所有的 value
    for e in pmap.values():
        print(e)

    if 23 in pmap: # 时间复杂度 O(logn)
        print("set 中包含了 2")

    del pmap[23]   # 时间复杂度 O(logn)
    print(pmap)   # SortedDict({12: 13, 99: 12})