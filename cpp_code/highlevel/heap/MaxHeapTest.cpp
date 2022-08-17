/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>
#include "./MaxHeap.cpp"

using namespace std;

bool compare(int x, int y) {
    return x > y;
}

int main() {
    int n = 10000;

    // 大顶堆
    // MaxHeap<int, greater<int>>* heap = new MaxHeap<int, greater<int>>();

    // 小顶堆
    // MaxHeap<int, less<int>>* heap = new MaxHeap<int, less<int>>();

    // 你可以可以自定义比较逻辑 - 大顶堆
    MaxHeap<int, decltype(&compare)>* heap = new MaxHeap<int, decltype(&compare)>(compare);

    // 1. 往堆中添加 10000 个随机整数
    for (int i = 0; i < n; i++) {
        heap->add(rand() % 10000);
    }

    // 2. 依次从堆中取出 10000 个整数，并依次放入到数组中
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = heap->removeMax();
    }

    // 3. 判断先拿出来的元素是最大的，如果不是的话，则说明不符合堆的性质
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < arr[i]) {
            cout << "Error" << endl;
            throw "Error";
        }
    }

    cout << "Test MaxHeap Succ" << endl;
    return 0;
}