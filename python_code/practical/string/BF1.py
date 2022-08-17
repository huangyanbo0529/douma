# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


# 时间复杂度：O(mn)
# 空间复杂度：O(1)
def indexOf(mainStr, pattern):
    m, n = len(mainStr), len(pattern)
    if m < n:
        return -1

    for i in range(m):
        # 1. 比对后面的字符，如果相等的话，一直比对下去
        k = i
        for j in range(n):
            if k < m and pattern[j] == mainStr[k]:
                k += 1
                # 2. 如果 j 是模式串的最后一个字符，说明匹配到了模式串
                if j == n - 1:
                    return i
            else:
                break

    return -1


if __name__ == '__main__':
    mainStr = "    your code"
    pattern = "your"
    print(indexOf(mainStr, pattern))