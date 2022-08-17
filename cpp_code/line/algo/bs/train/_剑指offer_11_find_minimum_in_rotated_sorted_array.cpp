class Solution {
public:
    // 不包含重复元素
    int findMin1(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }

    // 包含重复元素
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else if (nums[mid] < nums[right]) right = mid;
            else right--;
        }
        return nums[left];
    }
};