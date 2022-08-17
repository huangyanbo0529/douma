def firstTargetElement(nums, target):
    if nums is None or len(nums) == 0:
        return -1
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if target == nums[mid]:
            # 符合下面的两个条件之一就返回 mid ,否则去左边找 ：
            # 1. mid 是数组的第一个元素
            # 2. mid 前面的那个元素不等于 target
            if mid == 0 or nums[mid - 1] != target:
                return mid
            else:
                right = mid - 1
        elif target < nums[mid]:
            # 下一次搜索区间：[left...mid - 1]
            right = mid - 1
        else:
            # 下一次搜索区间：[mid + 1...right]
            left = mid + 1
        # left > right ：没有元素
        return -1


def firstGETargetElement(nums, target):
    if nums is None or len(nums) == 0:
        return -1
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if target <= nums[mid]:
            # 符合下面的两个条件之一就返回 mid ,否则去左边找 ：
            # 1. mid 是数组的第一个元素
            # 2. mid 前面的那个元素小于 target
            if mid == 0 or nums[mid - 1] < target:
                return mid
            else:
                right = mid - 1
        else:
            # 下一次搜索区间：[mid + 1...right]
            left = mid + 1
        # left > right ：没有元素
        return -1


def lastTargetElement(nums, target):
    if nums is None or len(nums) == 0:
        return -1
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if target == nums[mid]:
            # 符合下面的两个条件之一就返回 mid ,否则去右边找 ：
            # 1. mid 是数组的最后一个元素
            # 2. mid 后面的那个元素不等于 target
            if mid == len(nums) - 1 or nums[mid + 1] != target:
                return mid
            else:
                left = mid + 1
        elif target < nums[mid]:
            # 下一次搜索区间：[left...mid - 1]
            right = mid - 1
        else:
            # 下一次搜索区间：[mid + 1...right]
            left = mid + 1
        # left > right ：没有元素
        return -1


def lastLETargetElement(nums, target):
    if nums is None or len(nums) == 0:
        return -1
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if target >= nums[mid]:
            # 符合下面的两个条件之一就返回 mid ,否则去右边找 ：
            # 1. mid 是数组的最后一个元素
            # 2. mid 后面的那个元素大于 target
            if mid == len(nums) - 1 or nums[mid + 1] > target:
                return mid
            else:
                left = mid + 1
        else:
            right = mid - 1
        # left > right ：没有元素
        return -1