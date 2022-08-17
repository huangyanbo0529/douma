# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
from typing import List


# 没有重复元素
def findMin1(self, nums: List[int]) -> int:
    left, right = 0, len(nums) - 1
    while left < right:
        mid = (left + right) // 2
        if nums[mid] < nums[right]: right = mid
        else: left = mid + 1
    return nums[left]


# 包含重复元素
def findMin(self, nums: List[int]) -> int:
    if len(nums) == 1: return nums[0]
    left, right = 0, len(nums) - 1
    while left < right:
        mid = (left + right) // 2
        if nums[mid] > nums[right]: left = mid + 1
        elif nums[mid] < nums[right]: right = mid
        else: right -= 1
    return nums[left]