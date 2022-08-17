/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>

using namespace std;

int firstTargetElement(vector<int> nums, int target) {
    if (nums.size() == 0) return -1;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target == nums[mid]) {
            // 符合下面的两个条件之一就返回 mid ,否则去左边找：
            // 1. mid 是数组的第一个元素
            // 2. mid 前面的那个元素不等于 target
            if (mid == 0 || nums[mid - 1] != target) return mid;
            else right = mid - 1;
        } else if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int firstGETargetElement(vector<int> nums, int target) {
    if (nums.size() == 0) return -1;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target <= nums[mid]) {
            // 符合下面的两个条件之一就返回 mid ：
            // 1. mid 是数组的第一个元素
            // 2. mid 前面的那个元素小于 target
            if (mid == 0 || nums[mid - 1] < target) return mid;
            else right = mid - 1;
        } else { // target > nums[mid]
            left = mid + 1;
        }
    }
    return -1;
}

int lastTargetElement(vector<int> nums, int target) {
    if (nums.size() == 0) return -1;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target == nums[mid]) {
            // 符合下面的两个条件之一就返回 mid ：
            // 1. mid 是数组的最后一个元素
            // 2. mid 后面的那个元素不等于 target
            if (mid == nums.size() - 1 || nums[mid + 1] != target) return mid;
            else left = mid + 1;
        } else if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int lastLETargetElement(vector<int> nums, int target) {
    if (nums.size() == 0) return -1;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target >= nums[mid]) {
            if (mid == nums.size() - 1 || nums[mid + 1] > target) return mid;
            else left = mid + 1;
        } else { // target < nums[mid]
            right = mid - 1;
        }
    }
    return -1;
}