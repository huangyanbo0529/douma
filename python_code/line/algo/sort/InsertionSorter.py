

# 时间复杂度：O(n^2)
# 间复杂度：O(1)
def sort(data):
    if data is None or len(data) <= 1:
        return
    # 插入排序的轮数
    for i in range(1, len(data)):
        tmp = data[i]
        j = i
        while j > 0:
            if tmp < data[j - 1]:
                # 将较大的元素总是向右移动
                data[j] = data[j - 1]
            else:
                break
            j -= 1
        # 找到 i 对应的元素需要插入的位置
        data[j] = tmp


# 时间复杂度：O(n^2)
# 间复杂度：O(1)
def sort1(data):
    if data is None or len(data) <= 1:
        return
    # 插入排序的轮数
    for i in range(1, len(data)):
        tmp = data[i]
        for j in range(i, 0, -1):
            if tmp < data[j - 1]:
                data[j], data[j - 1] = data[j - 1], data[j]
            else:
                break


if __name__ == '__main__':
    data = [12, 23, 36, 9, 24, 42]
    sort1(data)
    print(data)
