

def sort(data):
    if data is None or len(data) <= 1:
        return

    # 1. 找到数组中的最大值，初始化计数器
    max_num = min_num = data[0]
    for i in range(1, len(data)):
        max_num = max(max_num, data[i])
        min_num = min(min_num, data[i])
    count = [0] * (max_num - min_num + 1)

    # 2. 计数
    for i in range(len(data)):
        count[data[i] - min_num] += 1

    # 3. 计数累加
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # 4. 计算每个元素在排序数组中的位置
    output = [0] * len(data)
    for i in range(len(data) - 1, -1, -1):
        j = data[i]
        k = count[j - min_num] - 1
        output[k] = data[i]
        count[j - min_num] -= 1

    # 5. 拷贝数组
    for i in range(len(data)):
        data[i] = output[i]


if __name__ == '__main__':
    data = [4, 2, -2, 8, 3, 3, 1]
    sort(data)
    print(data)