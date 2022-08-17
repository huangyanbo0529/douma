/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

void sort(int* data, int length) {
    if (data == nullptr || length <= 1) return;

    // 1. 计算递增序列
    int n = length;
    vector<int> list;
    int k = 1;
    int h;
    do {
        h = ((int) pow(3, k) - 1) / 2;
        // bug 修复：需要考虑 n < 3 的场景，
        // 当 n < 3 的时候，不应该 break，而应该将 h 添加到 list 中
        if (h > n / 3 && n >= 3) break;
        list.push_back(h); // 1, 4, 13, 40, 121......
        k++;
    } while (h <= n / 3);

    // 2. 希尔排序
    for (k = list.size() - 1; k >= 0 ; k--) { // 倒序遍历
        h = list[k];
        // 将数组变为 h 有序
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h; j = j - h) {
                if (data[j] < data[j - h]) {
                    swap(data[j], data[j - h]);
                } else {
                    break;
                }
            }
        }
    }
}

void sort1(int* data, int length) {
    if (data == nullptr || length <= 1) return;

    // 1. 计算递增序列
    int n = length;
    int h = 1;
    while (h < n / 3) h = 3 * h + 1; // 1, 4, 13, 40, 121......

    // 2. 希尔排序
    while (h >= 1) {
        // 将数组变为 h 有序
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h; j = j - h) {
                if (data[j] < data[j - h]) {
                    swap(data[j], data[j - h]);
                } else {
                    break;
                }
            }
        }
        h = h / 3;
    }
}

int main() {
    int data[] = {2, 5, 1, 23, 22, 33, 56, 12, 5, 3, 5, 6, 8, 2, 3, 4};
    sort(data, 16);
    stringstream fmt;
    for (int i = 0; i < 16; ++i) {
        fmt << to_string(data[i]) << ",";
    }
    cout << fmt.str() << endl;
    return 0;
}