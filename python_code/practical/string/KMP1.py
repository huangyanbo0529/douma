# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


# 时间复杂度：O(n^3)
def getNext(pattern):
    n = len(pattern)
    # bug 修复： 如果只有一个字符的话，就不计算 next 数组
    if n == 1:
        return []
    next = [-1] * (n - 1)
    for i in range(1, n - 1):
        # 1. 拿到模式串中 [0...i] 这个好前缀
        goodPrefix = pattern[0:i + 1]
        # 2. 计算当前好前缀的【最长匹配前缀子串】结尾字符的下标
        for j in range(i, 0, -1):
            # 2.1 拿到好前缀的 [j, i] 这个后缀字符串
            suffix = goodPrefix[j:]
            # 2.2 将后缀的每个字符和好前缀的前缀的每个字符比较
            # 得到第一个不相等的字符所在的位置 k
            k = -1
            while k < len(suffix):
                k += 1
                if suffix[k] != goodPrefix[k]:
                    break
            # 2.3 如果前缀匹配了后缀字符串，那么更新【最长匹配前缀字符串】结尾字符的下标
            if k == len(suffix):
                # 注意：next[i] 之前可能已经计算过，所以我们需要取最大值
                next[i] = max(k - 1, next[i])
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