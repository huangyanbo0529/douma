// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


// 单元测试见：堆和优先队列测试页面.html
export class DataStream2 {
    // 从外面传一个最大堆
    constructor(maxHeap) {
        // 大顶堆
        this.maxHeap = maxHeap
    }

    // O(logn)
    add(val) {
        this.maxHeap.add(val)
    }

    // O(logn)
    removeMax() {
        return this.maxHeap.remove()
    }
}