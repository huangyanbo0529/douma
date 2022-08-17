# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


def walkStair(n: int) -> int:
    if n == 1:
        return 1
    if n == 2:
        return 2
    return walkStair(n - 1) + walkStair(n - 2)


def fibonacci(n: int) -> int:
    if n == 1:
        return 1
    # bug 修复：斐波那契数列：1,1,2,3,5,8,13.....
    if n == 2:
        return 1
    fib1 = fibonacci(n - 1)
    fib2 = fibonacci(n - 2)
    return fib1 + fib2


def sum(n: int) -> int:
    if n == 1:
        return 1;
    return n + sum(n - 1)


def sum1(n: int) -> int:
    if n == 1:
        return 1;
    sub_problem = sum2(n - 2)
    res = n + sub_problem
    return res


def sum2(n: int) -> int:
    if n == 1:
        return 1;
    sub_problem = sum(n - 3)
    res = n + sub_problem
    return res


def a(times: int) -> None:
    if times == 0:
        return
    print("前参数 times = {}".format(times))
    a(times - 1)
    print("后参数 times = {}".format(times))


def a() -> None:
    print("调用方法 a()")
    a()
    print("调用本身结束")