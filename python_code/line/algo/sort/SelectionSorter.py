

# 时间复杂度：O(n^2)
# 间复杂度：O(1)
def sort(data):
    if data is None or len(data) <= 1:
        return
    # 控制选择排序的轮数
    for i in range(0, len(data)):
        # 找到 [i, n) 中的最小元素所在的索引
        min_num_index = i
        for j in range(i + 1, len(data)):
            if data[j] < data[min_num_index]:
                min_num_index = j

        # 将 data[i] 和最小元素进行交换
        data[i], data[min_num_index] = data[min_num_index], data[i]


if __name__ == '__main__':
    data = [12, 23, 36, 9, 24, 42]
    sort(data)
    print(data)
