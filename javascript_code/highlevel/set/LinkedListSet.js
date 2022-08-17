// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


// 单元测试见 Set 集合测试页面.html
export class LinkedListSet {
    // 从外面传入一个单向链表
    constructor(linkedList) {
        this.data = linkedList
    }

    size() {
        return this.data.getSize()
    }

    isEmpty() {
        return this.data.isEmpty()
    }

    add(e) { // O(n)
        if (!this.data.contains(e)) {
            this.data.addFirst(e)
        }
    }

    remove(e) {
        this.data.removeElement(e)
    }

    contains(e) {
        return this.data.contains(e)
    }

    toString() {
        return `ArraySet{ data = ${this.data.toString()} }`
    }
}