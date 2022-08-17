
def sort(data):
    if data is None or len(data) <= 1:
        return
    # 1. 计算递增序列
    n, list, k = len(data), [], 1
    h = (pow(3, k) - 1) // 2
    '''
    // bug 修复：需要考虑 n < 3 的场景，
    // 当 n < 3 的时候，应该将 h 添加到 list 中
    '''
    if n < 3:
        list.append(h)
    while h <= n // 3:
        # 1, 4, 13, 40, 121......
        list.append(h)
        k += 1
        h = (pow(3, k) - 1) // 2

    # 2. 希尔排序
    for k in range(len(list) - 1, -1, -1):
        h = list[k]
        # 将数组变为 h 有序
        for i in range(h, n):
            for j in range(i, h - 1, -h):
                if data[j] < data[j - h]:
                    data[j], data[j - h] = data[j - h], data[j]
                else:
                    break

def sort1(data):
    if data is None or len(data) <= 1:
        return
    # 1. 计算递增序列
    n, h = len(data), 1
    while h < n // 3:
        # 1, 4, 13, 40, 121......
        h = 3 * h + 1

    # 2. 希尔排序
    while h >= 1:
        # 将数组变为 h 有序
        for i in range(h, n):
            for j in range(i, h - 1, -h):
                if data[j] < data[j - h]:
                    data[j], data[j - h] = data[j - h], data[j]
                else:
                    break
        h = h // 3


if __name__ == '__main__':
    data = [2, 5, 1, 23, 22, 33, 56, 12, 5, 3, 5, 6, 8, 2, 3, 4]
    sort(data)
    print(data)