

# 时间复杂度：O(n^2)
# 间复杂度：O(1)
def sort(data):
    if data is None or len(data) <= 1:
        return
    # 控制冒泡轮数
    for round in range(1, len(data) + 1):
        has_swap = False
        compare_times = len(data) - round
        # 控制每轮比较次数
        for i in range(compare_times):
            if data[i] > data[i + 1]:
                data[i], data[i + 1] = data[i + 1], data[i]
                has_swap = True
        if not has_swap:
            break


if __name__ == '__main__':
    data = [12, 23, 36, 9, 24, 42]
    sort(data)
    print(data)
