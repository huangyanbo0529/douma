/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>
#include <sstream>

using namespace std;

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
void sort(int* data, int length) {
    if (data == nullptr || length <= 1) return;

    // 1. 找到数组中的最大值，初始化计数器
    int max = data[0];
    int min = data[0];
    for (int i = 1; i < length; i++) { // O(n)
        if (data[i] > max) max = data[i];
        if (data[i] < min) min = data[i];
    }
    int countLen = max - min + 1;
    // 每个元素初始化 0
    int count[countLen];
    for (int i = 0; i < countLen; i++) {
        count[i] = 0;
    }

    // 2. 计数
    for (int i = 0; i < length; i++) { // O(n)
        count[data[i] - min]++;
    }

    // 3. 计数累加
    for (int i = 1; i < countLen; i++) { // O(k)
        count[i] += count[i - 1];
    }

    // 4. 计算每个元素在排序数组中的位置
    int* output = new int[length];
    for (int i = length - 1; i >= 0; i--) { // O(n)
        int j = data[i];
        int k = count[j - min] - 1;
        output[k] = data[i];

        count[j - min]--;
    }

    // 5. 拷贝数组
    for (int i = 0; i < length; i++) { // O(n)
        data[i] = output[i];
    }
}

int main() {
    int data[] = {4, 2, -2, 8, 3, 3, 1};
    sort(data, 7);
    stringstream fmt;
    for (int i = 0; i < 7; ++i) {
        fmt << to_string(data[i]) << ",";
    }
    cout << fmt.str() << endl;
    return 0;
}