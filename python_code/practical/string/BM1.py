# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


def genBadCharIndexMap(pattern):
    bc = dict()
    for i in range(len(pattern)):
        bc[pattern[i]] = i
    return bc

"""
// 时间复杂度：<= O((m - n)*n)
// 最好情况下时间复杂度：O(m/n)
// 空间复杂度：O(n)
// 使用坏字符规则实现 BM
"""
def indexOf(mainStr, pattern):
    m, n = len(mainStr), len(pattern)
    if m < n:
        return -1

    # 数据(模式串)预处理, 构建坏字符哈希表
    bc = genBadCharIndexMap(pattern)
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

        """
        4. 往后移动 y - x 位
        bug 修复：坏字符在模式串的中位置可能会大于 y，即 x 有可能大于 y
        比如：主串为 aaabaaabaaabaaaa 模式串为 aba
        解决方案就是：如果 y < x 的话，那么去选择往前走 1 步
        """
        i = i + max(1, y - x)

    return -1


if __name__ == '__main__':
    mainStr = "aaabaaabaaabaaaa"
    pattern = "aba"
    print(indexOf(mainStr, pattern))