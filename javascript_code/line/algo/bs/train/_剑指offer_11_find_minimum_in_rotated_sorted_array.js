
// 没有重复元素
var findMin1 = function(nums) {
    let left = 0, right = nums.length - 1
    while (left < right) {
        const mid = Math.floor((left + right) / 2)
        if (nums[mid] > nums[right]) left = mid + 1
        else right = mid
    }
    return nums[left]
};

// 包含重复元素
var findMin = function(nums) {
    if (nums.length == 1) return nums[0]
    let left = 0, right = nums.length - 1
    while (left < right) {
        const mid = Math.floor((left + right) / 2)
        if (nums[mid] > nums[right]) left = mid + 1
        else if (nums[mid] < nums[right]) right = mid
        else right--
    }
    return nums[left]
};