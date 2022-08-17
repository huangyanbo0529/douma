/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include "./MaxHeap.cpp"

template <typename E, typename Compare>
class PriorityQueue {
private:
    MaxHeap<E, Compare>* maxHeap;

public:
    PriorityQueue() {
        this->maxHeap = new MaxHeap<E, Compare>();
    }

    PriorityQueue(Compare __comp) {
        this->maxHeap = new MaxHeap<E, Compare>(__comp);
    }

    int getSize() {
        return maxHeap->size();
    }

    bool sEmpty() {
        return maxHeap->isEmpty();
    }

    void enqueue(E e) {
        maxHeap->add(e);
    }

    E dequeue() {
        return maxHeap->removeMax();
    }

    E getFront() {
        return maxHeap->findMax();
    }
};