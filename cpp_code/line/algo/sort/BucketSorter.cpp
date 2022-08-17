/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

using swap;
using vector;

void sortR(vector<int>& data, int lo, int hi) {
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
void quickSort(vector<int>& data) {
    if (data.size() <= 1) return;

    sortR(data, 0, data.size() - 1);
}

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
void sort(int* data, int length) {
    if (data == nullptr || length <= 1) return;

    // 1. 创建几个空的 bucket
    int maxValue = data[0];
    for (int i = 0; i < length; ++i) {
        maxValue = max(maxValue, data[i]);
    }
    /*
    这里为什么是除以 10 呢？
    在视频中，我们讲过，假设数组中的元素的大小是 0 到 39
    然后我们想划分成 4 个桶，所以 39 / 10 + 1 = 4

    这里需要注意的是：bucketNum 的计算是根据场景确定的，不同的场景 bucketNum 的计算方式是不同的
    所以 bucketNum 的计算之前，需要确定桶排序使用的场景
     */
    int bucketNum = maxValue / 10 + 1; // 39 / 10 + 1 = 4
    vector<vector<int>> buckets(bucketNum);

    // 2. 将所有的元素添加进对应的 bucket
    for (int i = 0; i < length; i++) {
        // 计算当前元素应该被分配到哪一个桶里
        int index = data[i] / 10;
        buckets[index].push_back(data[i]);
    }

    // 3. 对每一个 bucket 中的元素进行排序
    for (int i = 0; i < bucketNum; i++) {
        // 注意，一定要传引用，所以需要加上 &
        vector<int>& bucketData = buckets[i];
        quickSort(bucketData);
    }

    // 4. 从 buckets 中拿到排序后的数组
    int index = 0;
    for (int i = 0; i < bucketNum; i++) {
        vector<int> bucketData = buckets[i];
        for (int j = 0; j < bucketData.size(); j++) {
            data[index++] = bucketData[j];
        }
    }
}

int main() {
    int data[] = {12, 5, 1, 23, 22, 33, 56, 12, 5, 3, 5, 6, 8, 2, 3, 4};
    sort(data, 16);
    stringstream fmt;
    for (int i = 0; i < 16; ++i) {
        fmt << to_string(data[i]) << ",";
    }
    cout << fmt.str() << endl;
    return 0;
}