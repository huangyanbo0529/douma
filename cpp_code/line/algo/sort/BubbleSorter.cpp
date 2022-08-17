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

    for (int round = 1; round <= length; ++round) { // 控制冒泡轮数
        bool hasSwap = false;
        int compareTimes = length - round;
        for (int i = 0; i < compareTimes; ++i) { // 控制每轮比较次数
            if (data[i] > data[i + 1]) {
                swap(data[i], data[i + 1]);
                hasSwap = true;
            }
        }
        if (!hasSwap) break;
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