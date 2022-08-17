def f(nums):
    # 对传进来的数组进行修改
    nums[2] = 999999


def sap(nums, i, j):
    nums[i], nums[j] = nums[j], nums[i]


if __name__ == '__main__':
    nums = [1, 2, 3]
    f(nums)
    print(nums)
