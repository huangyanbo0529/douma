# 时间复杂度：O(nlogn)
# 空间复杂度：O(n)
def sort(data):
    if data is None or len(data) <= 1:
        return
    tmp = [0] * len(data)
    sortR(data, 0, len(data) - 1, tmp)


# 给子数组进行排序，子问题
def sortR(data, left, right, tmp):
    # 终止递归条件
    if left == right:
        return
    # 分别对两个子问题求解
    mid = (left + right) // 2
    sortR(data, left, mid, tmp)
    sortR(data, mid + 1, right, tmp)
    # 合并两个有序的数组，即合并 [left...mid] 和 [mid + 1, right]
    # [left...mid] 和 [mid + 1, right] 这两个数组在上面已经排过序了
    merge2(data, left, mid, right, tmp)


# 第一种合并的方法
def merge(data, left, mid, right, tmp):
    tmp_pos, i, j = left, left, mid + 1
    # 将左边和右边的元素按照顺序拷贝到临时的数组中
    while i <= mid and j <= right:
        if data[i] <= data[j]:
            tmp[tmp_pos] = data[i]
            tmp_pos, i = tmp_pos + 1, i + 1
        else:
            tmp[tmp_pos] = data[j]
            tmp_pos, j = tmp_pos + 1, j + 1
    # 如果左边还有元素，则直接将左边的元素拷贝到临时数组
    while i <= mid:
        tmp[tmp_pos] = data[i]
        tmp_pos, i = tmp_pos + 1, i + 1
    # 如果右边还有元素，则直接将右边的元素拷贝到临时数组
    while j <= right:
        tmp[tmp_pos] = data[j]
        tmp_pos, j = tmp_pos + 1, j + 1
    # 拷贝
    for i in range(left, right + 1):
        data[left] = tmp[i]
        left += 1


def merge2(data, left, mid, right, tmp):
    for i in range(left, right + 1):
        tmp[i] = data[i]
    i, j = left, mid + 1
    for k in range(left, right + 1):
        # 左边没有元素，右边有元素
        if i == mid + 1:
            data[k] = tmp[j]
            j += 1
        # 左边有元素，右边没有元素
        elif j == right + 1:
            data[k] = tmp[i]
            i += 1
        elif tmp[i] <= tmp[j]:
            data[k] = tmp[i]
            i += 1
        else:
            # bug 修复：这个是 tmp[j++]
            data[k] = tmp[j]
            j += 1


def sortBU(data):
    if data is None or len(data) <= 1:
        return
    length = len(data)
    tmp = [0] * length
    size = 1
    while size < length:
        for left in range(0, length - size, 2 * size):
            mid = left + size - 1
            right = min(left + 2 * size - 1, length - 1)
            merge(data, left, mid, right, tmp)
        size += size


if __name__ == '__main__':
    data = [34, 33, 12, 78, 21, 1, 98, 100]
    sortBU(data)
    print(data)
