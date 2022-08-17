/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;


// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
void sort(int* data, int length) {
    if (data == nullptr || length <= 1) return;

    for (int i = 0; i < length; ++i) { // 插入排序的轮数
        int tmp = data[i];
        int j;
        for (j = i; j > 0; --j) {
            if (tmp < data[j - 1]) {
                // 将较大的元素总是向右移动
                data[j] = data[j - 1];
            } else {
                break;
            }
        }
        // 找到 i 对应的元素需要插入的位置
        data[j] = tmp;
    }
}

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
void sort1(int* data, int length) {
    if (data == nullptr || length <= 1) return;

    for (int i = 0; i < length; ++i) { // 插入排序的轮数
        for (int j = i; j > 0; --j) {
            if (data[j] < data[j - 1]) {
                swap(data[j], data[j - 1]);
            } else {
                break;
            }
        }
    }
}

int main() {
    int data[] = {12, 23, 36, 9, 24, 42};
    sort(data, 6);
    stringstream fmt;
    for (int i = 0; i < 6; ++i) {
        fmt << to_string(data[i]) << ",";
    }
    cout << fmt.str() << endl;
    return 0;
}