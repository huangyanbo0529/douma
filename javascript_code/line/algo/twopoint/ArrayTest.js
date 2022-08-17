

const f = function (nums) {
    // 对传进来的数组进行修改
    nums[2] = 999999
}

const swap = function (nums, i, j) {
    [nums[i], nums[j]] = [nums[j], nums[i]]
}

const nums = [1, 2, 3]
f(nums)
console.log(nums)

swap(nums, 0, 2)
console.log(nums)