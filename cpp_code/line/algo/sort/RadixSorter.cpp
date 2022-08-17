/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>
#include <sstream>

using namespace std;

void countSort(int* data, int exp, int length) { // 时间复杂度：O(n)
    // 之所以是 10，是因为数字只有 0...9 十个数字
    // 每个元素初始化 0
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < length; i++) {
        // 个位数： (234 / 1) % 10 = 4
        // 十位数： (234 / 10) % 10 = 3
        // 百位数： (234 / 100) % 10 = 2
        int digit = (data[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    int* output = new int[length];
    for (int i = length - 1; i >= 0; i--) {
        int digit = (data[i] / exp) % 10;
        int k = count[digit] - 1;
        output[k] = data[i];
        count[digit]--;
    }

    for (int i = 0; i < length; i++)
        data[i] = output[i];
}

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
void sort(int* data, int length) {
    if (data == nullptr || length <= 1) return;

    // 1. 找到最大值  4006869915
    int max = data[0];
    for (int i = 1; i < length; i++) {
        if (data[i] > max) max = data[i];
    }

    // 2. 对数组按照每个元素的每位进行计数排序
    for (int exp = 1; max / exp > 0; exp *= 10) { // O(n)
        countSort(data, exp, length); // 时间复杂度：O(n)
    }
}



int main() {
    int data[] = {4512, 4231, 31923, 2165, 1141};
    sort(data, 5);
    stringstream fmt;
    for (int i = 0; i < 5; ++i) {
        fmt << to_string(data[i]) << ",";
    }
    cout << fmt.str() << endl;
    return 0;
}