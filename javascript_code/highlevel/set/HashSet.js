// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


// 单元测试见 Set 集合测试页面.html
export class HashSet {
    constructor(__hash) {
        this.data = new Array(10).fill(undefined)
        this.__size = 0
        this.__hash = __hash
    }

    hash(e, len) {
        return Math.abs(this.__hash(e)) % len
    }

    size() {
        return this.__size
    }

    isEmpty() {
        return this.__size == 0
    }

    add(e) { // O(1)
        const index = this.hash(e, this.data.length)
        // bug 修复：为 undefined 的时候才插入
        if (this.data[index] == undefined) {
            this.data[index] = e
            this.__size++
            if (this.__size == this.data.length) {
                this.resize(2 * this.data.length)
            }
        }
    }

    resize(newCapacity) {
        const newData = new Array(newCapacity).fill(undefined)
        for (let i = 0; i < this.data.length; i++) {
            if (this.data[i] != undefined) {
                const newIndex = this.hash(this.data[i], newCapacity)
                newData[newIndex] = this.data[i]
            }
        }
        this.data = newData
    }

    remove(e) { // O(1)
        const index = this.hash(e, this.data.length)
        // bug 修复：在删除某个元素之前，先判断这个元素是否存在
        // 存在的话才删除
        if (this.data[index] != undefined) {
            this.data[index] = undefined
            this.__size++
        }
    }

    contains(e) {
        const index = this.hash(e, this.data.length)
        return this.data[index] != undefined
    }

    toString() {
        return `ArraySet{ data = ${this.data} }`
    }
}