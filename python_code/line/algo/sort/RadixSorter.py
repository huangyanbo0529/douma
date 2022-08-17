

# 基数排序
# 时间复杂度：O(n)
# 空间复杂度：O(1)
def sort(data):
    if data is None or len(data) <= 1:
        return

    # 1. 找到最大值  4006869915
    max_num = data[0]
    for i in range(1, len(data)):
        max_num = max(max_num, data[i])

    # 2. 对数组按照每个元素的每位进行计数排序
    exp = 1
    while max_num // exp > 0:
        countSort(data, exp)
        exp *= 10

def countSort(data, exp):
    # 之所以是 10，是因为数字只有 0...9 十个数字
    count = [0] * 10

    # 2. 计数
    for i in range(len(data)):
        # 个位数： (234 / 1) % 10 = 4
        # 十位数： (234 / 10) % 10 = 3
        # 百位数： (234 / 100) % 10 = 2
        digit = (data[i] // exp) % 10
        count[digit] += 1

    # 3. 计数累加
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # 4. 计算每个元素在排序数组中的位置
    output = [0] * len(data)
    for i in range(len(data) - 1, -1, -1):
        digit = (data[i] // exp) % 10
        k = count[digit] - 1
        output[k] = data[i]
        count[digit] -= 1

    # 5. 拷贝数组
    for i in range(len(data)):
        data[i] = output[i]


if __name__ == '__main__':
    data = [4512, 4231, 31923, 2165, 1141]
    sort(data)
    print(data)