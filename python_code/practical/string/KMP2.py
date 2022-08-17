# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


# 时间复杂度：O(n^3)
def getNext(pattern):
    n = len(pattern)
    # bug 修复： 如果只有一个字符的话，就不计算 next 数组
    if n == 1:
        return []
    next = [0] * (n - 1)
    next[0] = -1
    for j in range(1, n - 1):
        if pattern[next[j - 1] + 1] == pattern[j]:
            next[j] = next[j - 1] + 1
        else:
            pre = next[j - 1]
            while pre >= 0 and pattern[pre + 1] != pattern[j]:
                # 看前一个【最长匹配前缀字符串】
                pre = next[pre]

            if pattern[pre + 1] == pattern[j]:
                next[j] = pre + 1
            else:
                next[j] = pre
    # 最值问题
    return next


# 最好情况下时间复杂度：O(m)
# 最坏情况下时间复杂度：O(mn)
# 空间复杂度：O(n)
def indexOf(mainStr, pattern):
    m, n = len(mainStr), len(pattern)
    if m < n:
        return -1

    # 根据模式串所有的前缀，计算得到 next 数组
    next = getNext(pattern)

    j = 0
    for i in range(m):
        while j > 0 and mainStr[i] != pattern[j]:
            # 就不从头开始匹配了，直接跳到下一个最长匹配前缀字符串的结尾字符的下一个字符位置
            j = next[j - 1] + 1

        if mainStr[i] == pattern[j]:
            j += 1

        if j == n:
            return i - n + 1

    return -1


if __name__ == '__main__':
    mainStr = "aaabaaa"
    pattern = "baaa"
    print(indexOf(mainStr, pattern))