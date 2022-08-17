/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>

using namespace std;

void f(int* nums) {
    nums[2] = 99999;
}

void swapHelp(int* nums, int i, int j) {
    // c++ 有自带的 swap 函数
    swap(nums[i], nums[j]);
}

int main() {
    int nums[] = {1, 2, 3};
    f(nums);
    swapHelp(nums, 0, 2);
    for (int i = 0; i < 3; ++i) {
        cout << nums[i] << endl;
    }

    return 0;
}