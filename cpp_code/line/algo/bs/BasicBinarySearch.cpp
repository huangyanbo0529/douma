/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>

using namespace std;

// 时间复杂度：O(logn)
// 空间复杂度：O(1)
bool contains(vector<int> nums, int target) {
    if (nums.size() == 0) return false;

    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        // bug ：left + right 会溢出
        // 整数的最大值：2^31 - 1 = 2147483647
        int mid = left + (right -  left) / 2;
        if (target == nums[mid]) {
            return true;
        } else if (target < nums[mid]) {
            right = mid - 1; // 下一次搜索区间：[left...mid - 1]
        } else { // target > nums[mid]
            left = mid + 1; // 下一次搜索区间：[mid + 1...right]
        }
    }

    // left > right ：没有元素

    return false;
}

bool containsR(vector<int> nums, int left, int right, int target) {
    if (left > right) return false;

    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return true;

    if (target < nums[mid]) {
        return containsR(nums, left, mid - 1, target);
    } else {
        return containsR(nums, mid + 1, right, target);
    }
}

// 时间复杂度：O(logn)
// 空间复杂度：O(logn)
bool containsR(vector<int> nums, int target) {
    if (nums.size() == 0) return false;
    return containsR(nums, 0, nums.size() - 1, target);
}