
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
const contains = function (nums, target) {
    if (nums == null || nums.length == 0) return false

    let left = 0
    let right = nums.length - 1
    while (left <= right) {
        // bug ：left + right 会溢出
        // 整数的最大值：2^31 - 1 = 2147483647
        const mid = Math.floor(left + (right - left)/2)

        if (target == nums[mid]) {
            return true
        } else if (target < nums[mid]) {
            right = mid - 1 // 下一次搜索区间：[left...mid - 1]
        } else { // target > nums[mid]
            left = mid + 1 // 下一次搜索区间：[mid + 1...right]
        }
    }

    // left > right ：没有元素

    return false
}

const containsR = (nums, target) => {
    if (nums == null || nums.length == 0) return false

    const contains = (left, right) => {
        if (left > right) return false

        const mid = left + (right - left) / 2
        if (nums[mid] == target) return true

        if (target < nums[mid]) {
            return contains(left, mid - 1)
        } else {
            return contains(mid + 1, right)
        }
    }

    contains(0, nums.length - 1)
}