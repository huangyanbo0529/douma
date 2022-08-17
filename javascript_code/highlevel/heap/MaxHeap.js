
// 默认是大顶堆
// 以下代码是 java 中的 MaxHeap 的翻译
export class MaxHeap {

    constructor(comparator, data) {
        if (typeof comparator !== 'function') {
            throw new Error('MaxHeap expects a comparator function');
        }
        this._comparator = comparator
        if (data == undefined) {
            this.data = []
        } else {
            this.data = [...data]
            // O(n)
            for (let i = this.lastNonLeafIndex(); i >= 0; i--) { // O(n)
                this.siftDown(i) // O(logn)
            }
        }
    }

    // 返回堆中的元素个数
    size() {
        return this.data.length
    }

    // 判断堆是否为空
    isEmpty() {
        return this.data.length == 0
    }

    // 返回一个索引所表示的元素的左孩子节点的索引
    leftChild(index) {
        return index * 2 + 1
    }
    // 返回一个索引所表示的元素的右孩子节点的索引
    rightChild(index) {
        return index * 2 + 2
    }
    // 返回一个索引所表示的元素的父节点的索引
    parent(index) {
        if (index == 0) throw new Error("index-0 does not have parent")
        return Math.floor((index - 1) / 2)
    }
    // 返回最后一个非叶子节点的索引值
    lastNonLeafIndex() {
        // 最后一个叶子节点的索引
        const lastLeafIndex = this.data.length - 1
        // 返回最后一个叶子节点的父节点的索引值就是最后一个非叶子节点的索引
        return this.parent(lastLeafIndex)
    }

    // 往大顶堆中添加一个元素
    // 时间复杂度：O(logn)
    add(e) {
        // 1. 先将元素插入到数组的最后
        this.data.push(e)
        // // 2. 将最后一个节点 e 上浮
        this.siftUp(this.data.length - 1)
    }

    // 将数组中索引为 index 的元素进行上浮
    siftUp(index) {
        const e = this.data[index]
        // 循环比较并上浮，一直到节点是根节点
        while (index > 0) {
            const parentNode = this.data[this.parent(index)]

            if (this._comparator(e, parentNode) <= 0) break;

            // 将父节点插入到子节点中
            this.data[index] = parentNode

            // 更新需要插入的元素节点的索引为它之前的父节点的索引
            index = this.parent(index)
        }
        // 将节点插入到正确的位置上
        this.data[index] = e
    }

    // 相当于 java 中 MaxHeap 的 findMax 方法
    // 获取堆顶的元素
    peek() {
        if (this.data.length == 0) {
            throw new Error("Heap is Empty")
        }
        return this.data[0]
    }

    // 相当于 java 中 MaxHeap 的 removeMax 方法
    // 删除并返回堆顶元素
    // 时间复杂度：O(logn)
    remove() {
        const e = this.peek()
        // 1. 将最后一个节点替换根节点，并删除最后一个节点
        const last = this.data.pop()
        if (this.data.length == 0) return e
        this.data[0] = last

        // 2. 将新的根节点做下沉操作
        if (this.data.length > 0) this.siftDown(0)
        return e
    }

    siftDown(index) {
        const e = this.data[index]
        while (this.leftChild(index) < this.data.length) {
            // 1. 找到节点的左右子节点值最大的那个节点
            let maxNodeIndex = this.leftChild(index)
            if (this.rightChild(index) < this.data.length) {
                const rightElement = this.data[this.rightChild(index)]
                const leftElement = this.data[this.leftChild(index)]
                if (this._comparator(rightElement, leftElement) > 0) {
                    maxNodeIndex = this.rightChild(index)
                }
            }

            if (this._comparator(e, this.data[maxNodeIndex]) >= 0) break

            // 2. 将节点和最大节点的值比较，如果小的话，就需要交换
            this.data[index] = this.data[maxNodeIndex]

            index = maxNodeIndex
        }
        this.data[index] = e
    }

}

