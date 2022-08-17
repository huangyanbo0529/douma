/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

int partition(int* data, int lo, int hi) {
    int pivot = data[hi];
    int less = lo;
    int great = lo;
    for (; great <= hi - 1; great++) {
        if (data[great] < pivot) {
            swap(data[less], data[great]);
            less++;
        }
    }
    swap(data[less], data[hi]);
    return less;
}

void sortR(int* data, int lo, int hi) {
    if (lo >= hi) return;
    // 分区
    int j = partition(data, lo, hi);
    // 对左边数组排序
    sortR(data, lo, j - 1);// log2n
    // 对右边数组排序
    sortR(data, j + 1, hi); // log2n
}


// 时间复杂度：O(nlogn)
// 空间复杂度：O(1)
void sort(int* data, int length) {
    if (data == nullptr || length <= 1) return;

    sortR(data, 0, length - 1);
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