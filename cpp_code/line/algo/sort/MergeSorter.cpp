/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

void merge(int* data, int left, int mid, int right, int* tmp) {
    int tmpPos = left;
    int i = left;
    int j = mid + 1;
    // 将左边和右边的元素按照顺序拷贝到临时的数组中
    while (i <= mid && j <= right) {
        if (data[i] <= data[j]) {
            tmp[tmpPos++] = data[i++];
        } else { // data[i] > data[j]
            tmp[tmpPos++] = data[j++];
        }
    }
    // 如果左边还有元素，则直接将左边的元素拷贝到临时数组
    while (i <= mid) {
        tmp[tmpPos++] = data[i++];
    }
    // 如果右边还有元素，则直接将右边的元素拷贝到临时数组
    while (j <= right) {
        tmp[tmpPos++] = data[j++];
    }
    // 拷贝
    for (tmpPos = left; tmpPos <= right; tmpPos++) {
        data[left++] = tmp[tmpPos];
    }
}

void merge2(int* data, int left, int mid, int right, int* tmp) {
    for (int i = left; i <= right; i++) {
        tmp[i] = data[i];
    }

    int i = left;
    int j = mid + 1;
    for (int k = left; k <= right; k++) {
        if (i == mid + 1) { // 左边没有元素，右边有元素
            data[k] = tmp[j++];
        } else if (j == right + 1) { // 左边有元素，右边没有元素
            data[k] = tmp[i++];
        } else if (tmp[i] <= tmp[j]) {
            data[k] = tmp[i++];
        } else {
            // bug 修复：这个是 tmp[j++]
            data[k] = tmp[j++];
        }
    }
}

void sortR(int* data, int left, int right, int* tmp) {
    // 终止递归条件
    if (left == right) return;
    // 分别对两个子问题求解
    int mid = (left + right) / 2;
    sortR(data, left, mid, tmp);
    sortR(data, mid + 1, right, tmp);
    // 合并两个有序的数组，即合并 [left...mid] 和 [mid + 1, right]
    // [left...mid] 和 [mid + 1, right] 这两个数组在上面已经排过序了
    merge2(data, left, mid, right, tmp);
}

// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
void sort(int* data, int length) {
    if (data == nullptr || length <= 1) return;

    int* tmp = new int[length];
    sortR(data, 0, length - 1, tmp);
}

void sortBU(int* data, int length) {
    if (data == nullptr || length <= 1) return;
    int* tmp = new int[length];
    for (int size = 1; size < length; size += size) { // size 表示子数组的长度，1,2,4,8
        for (int left = 0; left < length - size; left += 2 * size) {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, length - 1);
            merge(data, left, mid, right, tmp);
        }
    }
}


int main() {
    int data[] = {34, 33, 12, 78, 21, 1, 98, 100};
    sortBU(data, 8);
    stringstream fmt;
    for (int i = 0; i < 8; ++i) {
        fmt << to_string(data[i]) << ",";
    }
    cout << fmt.str() << endl;
    return 0;
}