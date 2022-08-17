// 抖码算法，让算法学习变的简单有趣
// 作者：老汤



// 注意：js 虽然没有内置的优先队列，但是有其他人写好的优先队列库
// 链接：https://github.com/datastructures-js/priority-queue

export class PriorityQueue {
    constructor(maxHeap) {
        this.maxHeap = maxHeap
    }

    getSize() {
        return this.maxHeap.size();
    }

    isEmpty() {
        return this.maxHeap.isEmpty();
    }

    enqueue(e) {
        this.maxHeap.add(e);
    }

    dequeue() {
        return this.maxHeap.remove();
    }

    getFront() {
        return this.maxHeap.peek();
    }
}