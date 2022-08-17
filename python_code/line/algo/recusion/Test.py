# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


def sum(n: int) -> int:
    res = 0
    for i in range(1, n + 1):
        res += i
    return res


one = sum(1)
two = one + sum(1)
three = two + sum(2)