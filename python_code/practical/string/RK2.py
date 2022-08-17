# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


# 时间复杂度： O(1)
def calHashCode(mainStr, i, hashCodes, n):
    return hashCodes[i - 1] - (ord(mainStr[i - 1]) - ord('a')) \
           + (ord(mainStr[i + n - 1]) - ord('a'))


# abc => 0 + 1 + 2 = 3
# 时间复杂度：O(n)
def calFirstSubStrHashCode(string):
    n, hashCode = len(string),  0
    for i in range(n):
        hashCode += (ord(string[n - i - 1]) - ord('a'))
    return hashCode


# 时间复杂度：O(m - n)
# 空间复杂度：O(m - n)
def indexOf(mainStr, pattern):
    m, n = len(mainStr), len(pattern)
    if m < n:
        return -1

    # 1. 计算主串中 m - n + 1 个子串的哈希值
    hashCodes = [0] * (m - n + 1)
    # 计算第一个子串的 hash 值
    hashCodes[0] = calFirstSubStrHashCode(mainStr[0:n])
    for i in range(1, m - n + 1):
        # 根据前一个子串的 hash 值计算下一个子串的 hash 值
        hashCodes[i] = calHashCode(mainStr, i, hashCodes, n)

    # 2. 计算模式串的哈希值
    hashCode = calFirstSubStrHashCode(pattern)

    # 3. 在所有子串哈希值中，寻找是否有模式串的哈希值
    for i in range(m - n + 1):
        # abc = 0 + 1 + 2 = 3
        # cba = 2 + 1 + 0 = 3
        if hashCode == hashCodes[i]:
            # 解决哈希冲突问题：将子串和模式串重新对比一遍
            k, j = i, 0
            while j < n and k < m:
                if mainStr[k] != pattern[j]:
                    break
                if j == n - 1:
                    return i
                k, j = k + 1, j + 1

    return -1


if __name__ == '__main__':
    mainStr = "    your code"
    pattern = "your"
    print(indexOf(mainStr, pattern))