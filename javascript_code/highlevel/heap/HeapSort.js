// 抖码算法，让算法学习变的简单有趣
// 作者：老汤

// 单元测试见：堆和优先队列测试页面.html
export function sort(maxHeap) {
    // 1. 建堆，堆化 O(n)
    // const maxHeap = new MaxHeap(comparator, data)

    // 2. 排序
    const res = new Array(maxHeap.size())
    let i = maxHeap.size() - 1
    // O(nlogn)
    while (!maxHeap.isEmpty()) {
        res[i] = maxHeap.remove()
        i--
    }

    return res
}