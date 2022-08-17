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

    for (int i = 0; i < length; ++i) { // 控制选择排序的轮数
        // 找到 [i, n) 中的最小元素所在的索引
        int minNumIndex = i;
        for (int j = i + 1; j < length; ++j) {
            if (data[j] < data[minNumIndex]) {
                minNumIndex = j;
            }
        }
        // 将 data[i] 和最小元素进行交换
        swap(data[i], data[minNumIndex]);
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