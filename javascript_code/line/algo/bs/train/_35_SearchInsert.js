// 思路二：在循环体内排除没有目标值的区间
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
const searchInsert = function(nums, target) {
    if (nums.length == 0) return 0
    const n = nums.length
    if (target <= nums[0]) return 0
    if (target > nums[n - 1]) return n

    let left = 0, right = n - 1
    while (left < right) {
        const mid = Math.floor((left + right) / 2)
        if (nums[mid] == target) return mid
        else if (nums[mid] < target) left = mid + 1
        else right = mid
    }

    return left
};

// 思路一：在循环体内查找目标值
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
const searchInsert1 = function(nums, target) {
    if (nums.length == 0) return 0
    if (target > nums[nums.length - 1]) return nums.length
    // 二分查找第一个大于等于 target 的索引
    let left = 0
    let right = nums.length - 1
    while (left <= right) {
        const mid = left + (right - left) / 2
        if (target <= nums[mid]) {
            if (mid == 0 || nums[mid - 1] < target) return mid
            else right = mid - 1
        } else {
            left = mid + 1
        }
    }
    return -1
};

