/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <functional>
#include <sstream>
#include <iostream>

#include "./MaxHeap.cpp"

using namespace std;

// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
void sort(vector<int>& data) {
    // 1. 建堆，堆化 O(n)
    MaxHeap<int, greater<int>> maxHeap(data);

    // 2. 排序
    vector<int> tmp(data.size());
    int i = data.size() - 1;
    // O(nlogn)
    while (!maxHeap.isEmpty()) { // O(n)
        tmp[i] = maxHeap.removeMax(); // O(logn)
        i--;
    }

    // 3. 拷贝
    for (int j = 0; j < data.size(); j++) {
        data[j] = tmp[j];
    }
}

int main() {
    vector<int> data = {15, 17, 19, 13, 22, 16, 28, 30, 42, 66};
    sort(data);

    stringstream fmt;
    for (int i = 0; i < data.size(); ++i) {
        fmt << to_string(data[i]) << ",";
    }
    cout << fmt.str() << endl;

    return 0;
}