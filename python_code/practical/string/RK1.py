# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


# 时间复杂度：// O(n)
def calHashCode(string):
    return hash(string)


# 时间复杂度：O((m - n)*n)
# 空间复杂度：O(m - n)
def indexOf(mainStr, pattern):
    m, n = len(mainStr), len(pattern)
    if m < n:
        return -1

    # 1. 计算主串中 m - n + 1 个子串的哈希值
    hashCodes = [0] * (m - n + 1)
    for i in range(m - n + 1):
        hashCodes[i] = calHashCode(mainStr[i:i + n])

    # 2. 计算模式串的哈希值
    hashCode = calHashCode(pattern)

    # 3. 在所有子串哈希值中，寻找是否有模式串的哈希值
    for i in range(m - n + 1):
        if hashCode == hashCodes[i]:
            return i

    return -1


if __name__ == '__main__':
    mainStr = "    your code"
    pattern = "your"
    print(indexOf(mainStr, pattern))