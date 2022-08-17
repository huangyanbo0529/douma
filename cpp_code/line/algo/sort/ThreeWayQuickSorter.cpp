/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

void sortR(int* data, int lo, int hi) {
    if (lo >= hi) return;
    // 分区
    int pivot = data[hi];

    int less = lo;
    int great = hi;

    int i = lo;
    while (i <= great) {
        if (data[i] < pivot) {
            swap(data[i], data[less]);
            less++;
            i++;
        } else if (data[i] > pivot) {
            swap(data[i], data[great]);
            great--;
        } else {
            i++;
        }
    }

    sortR(data, lo, less - 1);
    sortR(data, great +1, hi);
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