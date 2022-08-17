# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


# 时间复杂度：O(mn)
# 空间复杂度：O(1)
def indexOf(mainStr, pattern):
    m, n = len(mainStr), len(pattern)
    if m < n:
        return -1

    first = pattern[0]
    for i in range(m):
        # 1. 找到等于模式串中第一个字符的位置
        if mainStr[i] != first:
            while i < m and mainStr[i] != first:
                i += 1

        if i < m:
            # 2. 比对后面的字符，如果相等的话，一直比对下去
            k, j = i + 1, 1
            # bug 修复，如果 j 已经超出了 pattern 范围
            # 说明已经找到了，则直接返回
            if j == n:
                return i
            while j < n and k < m:
                if mainStr[k] == pattern[j]:
                    # 3. 如果 j 是模式串的最后一个字符，说明匹配到了模式串
                    if j == n - 1:
                        return i
                else:  # 如果字符不相等，则退出循环
                    break
                k, j = k + 1, j + 1

    return -1


if __name__ == '__main__':
    mainStr = "    your code"
    pattern = "your"
    print(indexOf(mainStr, pattern))