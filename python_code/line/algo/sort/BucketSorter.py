from line.algo.sort import QuickSorter


def sort(data):
    if data is None or len(data) <= 1:
        return

    # 1. 创建几个空的 bucket
    max_value = data[0]
    for d in data:
        max_value = max(max_value, d)

    """
    这里为什么是除以 10 呢？
    在视频中，我们讲过，假设数组中的元素的大小是 0 到 39
    然后我们想划分成 4 个桶，所以 39 / 10 + 1 = 4

    这里需要注意的是：bucketNum 的计算是根据场景确定的，不同的场景 bucketNum 的计算方式是不同的
    所以 bucketNum 的计算之前，需要确定桶排序使用的场景
    """
    bucket_num = max_value // 10 + 1
    buckets = [None] * bucket_num

    # 2. 将所有的元素添加进对应的 bucket
    for i in range(len(data)):
        # 计算当前元素应该被分配到哪一个桶里
        index = data[i] // 10
        if buckets[index] is None:
            buckets[index] = []
        buckets[index].append(data[i])

    # 3. 对每一个 bucket 中的元素进行排序
    for i in range(bucket_num):
        bucket_data = buckets[i]
        if bucket_data is not None:
            QuickSorter.sort(bucket_data)

    # 4. 从 buckets 中拿到排序后的数组
    index = 0
    for i in range(bucket_num):
        bucket_data = buckets[i]
        if bucket_data is not None:
            for j in range(len(bucket_data)):
                data[index] = bucket_data[j]
                index += 1


if __name__ == '__main__':
    data = [2, 5, 1, 23, 22, 33, 56, 12, 5, 3, 5, 6, 8, 2, 3, 4]
    sort(data)
    print(data)