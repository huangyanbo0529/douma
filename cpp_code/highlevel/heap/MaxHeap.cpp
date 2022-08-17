/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>

using namespace std;

template <typename E, typename _Compare>
class MaxHeap {
private:
    vector<E> data;
    _Compare __comp;

public:
    MaxHeap(): __comp() {}

    MaxHeap(_Compare __comp): __comp(__comp) {}

    MaxHeap(vector<E> data) {
        this->data = data;
        for (int i = lastNonLeafIndex(); i >= 0; --i) {
            siftDown(i);
        }
    }

    // 返回堆中的元素个数
    int size() {
        return data.size();
    }

    // 判断堆是否为空
    bool isEmpty() {
        return data.empty();
    }
    // 返回一个索引所表示的元素的左孩子节点的索引
    int leftChild(int index) {
        return index * 2 + 1;
    }
    // 返回一个索引所表示的元素的右孩子节点的索引
    int rightChild(int index) {
        return index * 2 + 2;
    }
    // 返回一个索引所表示的元素的父节点的索引
    int parent(int index) {
        if (index == 0) {
            throw "index-0 does not have parent";
        }
        return (index - 1) / 2;
    }
    // 返回最后一个非叶子节点的索引值
    int lastNonLeafIndex() {
        // 最后一个叶子节点的索引
        int lastLeafIndex = data.size() - 1;
        // 返回最后一个叶子节点的父节点的索引值就是最后一个非叶子节点的索引
        return parent(lastLeafIndex);
    }
    // 往大顶堆中添加一个元素
    // 时间复杂度：O(logn)
    void add(E e) {
        // 1. 先将元素插入到数组的最后
        data.push_back(e);
        // 2. 将最后一个节点 e 上浮
        siftUp(data.size() - 1);
    }
    // 将数组中索引为 index 的元素进行上浮
    void siftUp(int index) {
        E e = data[index];
        // 循环比较并上浮，一直到节点是根节点
        while (index > 0) {
            E parentNode = data[parent(index)];

            if (!__comp(e, parentNode)) break;

            // 将父节点插入到子节点中
            data[index] = parentNode;

            // 更新需要插入的元素节点的索引为它之前的父节点的索引
            index = parent(index);
        }
        // 将节点插入到正确的位置上
        data[index] = e;
    }

    E findMax() {
        if (data.size() == 0)
            throw "Heap is Empty";
        return data.front();
    }

    // 从大顶堆中取出并删除最大值
    // 时间复杂度：O(logn)
    E removeMax() {
        E max = findMax();
        // 1. 将最后一个节点替换根节点
        E last = data.back();
        data[0] = last;

        // 2. 删除最后一个节点
        data.pop_back();

        // 3. 将新的根节点做下沉操作
        if (!data.empty()) siftDown(0);

        return max;
    }

    void siftDown(int index) {
        E e = data[index];
        while (leftChild(index) < data.size()) {
            // 1. 找到节点的左右子节点值最大的那个节点
            int maxNodeIndex = leftChild(index);
            if (rightChild(index) < data.size()) {
                if (__comp(data[rightChild(index)], data[leftChild(index)])) {
                    maxNodeIndex = rightChild(index);
                }
            }

            if (__comp(e, data[maxNodeIndex])) break;

            // 2. 将节点和最大节点的值比较，如果小的话，就需要交换
            data[index] = data[maxNodeIndex];

            index = maxNodeIndex;
        }
        data[index] = e;
    }
};