// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


// 单元测试见 Set 集合测试页面.html
export class BSTSet {
    // 传入一个二叉搜索树
    constructor(bst) {
        this.bst = bst
    }

    size() {
        return this.bst.getSize()
    }

    isEmpty() {
        return this.bst.isEmpty()
    }

    add(e) { // O(logn)
        this.bst.add(e)
    }

    remove(e) {
        this.bst.remove(e)
    }

    contains(e) {
        return this.bst.contains(e)
    }

    toString() {
        return `ArraySet{ data = ${this.bst.inOrder()} }`
    }
}