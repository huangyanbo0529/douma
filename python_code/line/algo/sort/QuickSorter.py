def sort(data):
    if data is None or len(data) <= 1:
        return
    sortR(data, 0, len(data) - 1)


def sortR(data, lo, hi):
    if lo >= hi:
        return
    # 分区
    j = partition(data, lo, hi)
    # 对左边数组排序
    sortR(data, lo, j - 1)
    # 对右边数组排序
    sortR(data, j + 1, hi)


def partition(data, lo, hi):
    pivot = data[hi]
    less = great = lo
    while great <= hi - 1:
        if data[great] < pivot:
            data[less], data[great] = data[great], data[less]
            less += 1
        great += 1
    data[less], data[hi] = data[hi], data[less]
    return less


if __name__ == '__main__':
    data = [34, 33, 12, 78, 21, 1, 98, 100]
    sort(data)
    print(data)
