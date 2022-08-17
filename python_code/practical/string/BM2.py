# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


def genBadCharIndexMap(pattern):
    bc = dict()
    for i in range(len(pattern)):
        bc[pattern[i]] = i
    return bc


def genGoodSuffixArr(pattern, suffix, prefix):
    n = len(pattern)
    for i in range(n - 1):
        j, k = i, 0
        while j >= 0 and pattern[j] == pattern[n - 1 - k]:
            k += 1
            suffix[k] = j
            j -= 1
        if j == -1:
            prefix[k] = True


# y 表示坏字符对应的模式串中的字符位置
def calMoveSteps(y, n, suffix, prefix):
    # k 表示好后缀的长度
    k = n - y - 1
    # 看看模式串中是否存在好后缀(第二种情况)
    if suffix[k] != -1:
        return y - suffix[k] + 1
    # 看看好后缀的后缀子串是否和模式串的前缀子串匹配(第三种情况)
    for i in range(y + 1, n):
        if prefix[n - i]:
            return i
    # 将整个模式串后移 n 位(第一种情况)
    return n


"""
// 时间复杂度：
// 最坏情况下，BM 算法的比较次数上限是 5m ：http://dl.acm.org/citation.cfm?id=1382431.1382552
// 最坏情况下，BM 算法的比较次数上限是 3m ：http://dl.acm.org/citation.cfm?id=127830
// 空间复杂度：O(n)
// 使用坏字符规则实现 BM
"""


def indexOf(mainStr, pattern):
    m, n = len(mainStr), len(pattern)
    if m < n:
        return -1

    # 数据(模式串)预处理, 构建坏字符哈希表
    bc = genBadCharIndexMap(pattern)

    # 数据预处理：构建好后缀规则
    suffix, prefix = [-1] * n, [False] * n
    genGoodSuffixArr(pattern, suffix, prefix)

    # i 表示每次匹配的时候，主串的起始位置，初始化为 0
    i = 0
    while i <= m - n:
        # 1. 找到第一个坏字符，从后往前匹配
        # 注意：这里如果使用 for 循环的话，最后会少减一次，所以改成 while 循环
        y = n
        while y >= 0:
            y -= 1
            if mainStr[i + y] != pattern[y]:
                break

        # 2. 表示匹配成功
        if y < 0:
            # 返回主串和模式串第一个匹配字符串的位置
            return i

        # 3. 匹配不成功，模式串往后移动
        # 先计算坏字符在模式串中的位置 x
        bacChar = mainStr[i + y]
        x = bc[bacChar] if bacChar in bc else -1
        badCharMoveSteps = y - x

        # 根据好后缀规则，计算移动的位数
        goodSuffixMoveSteps = 0
        if y < n - 1:  # 说明有好后缀，否则没有
            goodSuffixMoveSteps = calMoveSteps(y, n, suffix, prefix)

        # 4. 往后移动最大位数
        i = i + max(badCharMoveSteps, goodSuffixMoveSteps)

    return -1


if __name__ == '__main__':
    mainStr = "aaabaaa"
    pattern = "baaa"
    print(indexOf(mainStr, pattern))
