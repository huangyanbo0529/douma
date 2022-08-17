/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>
#include "./MaxHeap.cpp"

using namespace std;


class DataStream2 {
private:
    MaxHeap<int, greater<int>>* heap;

public:
    DataStream2() {
        this->heap = new MaxHeap<int, greater<int>>(greater<int>());
    }

    // O(logn)
    void add(int val) {
        heap->add(val);
    }

    // O(logn)
    int removeMax() {
        return heap->removeMax();
    }
};


int main() {
    DataStream2 dataStream;
    dataStream.add(3);
    cout << to_string(dataStream.removeMax()) << endl;

    dataStream.add(6);
    dataStream.add(5);
    cout << to_string(dataStream.removeMax()) << endl;

    dataStream.add(2);
    dataStream.add(1);
    cout << to_string(dataStream.removeMax()) << endl;

    return 0;
}