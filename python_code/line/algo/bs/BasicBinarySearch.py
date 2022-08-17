

# 时间复杂度：O(logn)
# 空间复杂度：O(1)
def contains(nums, target):
    if nums is None or len(nums) == 0:
        return False

    left, right = 0, len(nums) - 1
    while left <= right:
        # bug ：left + right 会溢出
        # 整数的最大值：2^31 - 1 = 2147483647
        mid = left + (right - left) // 2
        if target == nums[mid]:
            return True
        elif target < nums[mid]:
            # 下一次搜索区间：[left...mid - 1]
            right = mid - 1
        else:
            # 下一次搜索区间：[mid + 1...right]
            left = mid + 1
        # left > right ：没有元素
        return False


def containsR(nums, target):
    if nums is None or len(nums) == 0:
        return False
    return contains_help(nums, 0, len(nums) - 1, target)


def contains_help(nums, left, right, target):
    if left > right:
        return False
    mid = left + (right - left) // 2
    if nums[mid] == target:
        return True
    if target < nums[mid]:
        return contains_help(nums, left, mid - 1, target)
    else:
        return contains_help(nums, mid + 1, right, target)
