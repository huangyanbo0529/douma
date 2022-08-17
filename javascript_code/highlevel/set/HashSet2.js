// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


class Item {
    constructor(data) {
        this.data = data
        this.isDeleted = false
    }

    toString() {
        if (this.isDeleted) {
            return ""
        } else {
            return this.data
        }
    }
}

// 单元测试见 Set 集合测试页面.html
export class HashSet2 {
    constructor(__hash, __equal, loadFactor) {
        this.items = new Array(10).fill(null)
        this.__size = 0
        this.__hash = __hash
        this.__equal = __equal
        // 用于记录有多少标记删除的元素
        this.deleteCount = 0
        // 装载因子
        this.loadFactor = (loadFactor == undefined ? 0.75 : loadFactor)
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

    add(e) {  // 最好：O(1)，最坏：O(n)
        let index = this.hash(e, this.items.length)

        // addIndex 表示元素 e 需要插入的索引位置
        let addIndex = index;
        // isFirst 用于辅助找到元素 e 插入的位置
        let isFirst = true;

        // bug 修复：add 前先判断是否存在元素 e
        while (this.items[index] != null && !this.__equal(e, this.items[index].data)) {
            // 找到第一个等于 null 或者删除的元素，并记录赋值给 addIndex
            if ((this.items[index] == null || this.items[index].isDeleted) && isFirst) {
                addIndex = index;
                isFirst = false;
            }

            index++;
            index = index % this.items.length;
        }
        // 说明已经存在 e，则直接返回
        if (this.items[index] != null && !this.items[index].isDeleted) return;

        // 这个时候的 addIndex 对应的元素要么是 null ，要么是已经删除的元素
        // 如果 addIndex 对应的元素是标记为删除的元素，那么直接被覆盖了，标记为删除的元素个数减少 1
        if (this.items[addIndex] != null && this.items[addIndex].isDeleted) this.deleteCount--;
        this.items[addIndex] = new Item(e);
        this.__size++;

        if (this.__size >= this.items.length * this.loadFactor) {
            this.resize(2 * this.items.length);
        }
    }

    resize(newCapacity) {
        const newData = new Array(newCapacity).fill(null)
        for (let i = 0; i < this.items.length; i++) {
            if (this.items[i] != null && !this.items[i].isDeleted) {
                const newIndex = this.hash(this.items[i], newCapacity)
                newData[newIndex] = this.items[i]
            }
        }
        // 所有标记为删除的元素都清理掉了
        this.deleteCount = 0
        this.items = newData
    }

    remove(e) { // O(1)
        let index = this.hash(e, this.items.length)
        // 找到等于 e 或者元素为 null 的索引
        while (this.items[index] != null && !this.__equal(e, this.items[index].data)) {
            index++;
            index = index % this.items.length;
        }
        if (this.items[index] != null) {
            this.items[index].isDeleted = true;
            this.__size--;
            this.deleteCount++;
        }
        // 如果标记为删除的元素太多的话，我们进行 resize，清除标记为删除的元素
        // TODO：这里可能会产生时间复杂度震荡
        if (this.deleteCount + this.__size >= this.items.length * this.loadFactor) {
            this.resize(this.items.length);
        }
    }

    contains(e) {
        let index = this.hash(e, this.items.length)
        // 找到等于 e 或者元素为 null 的索引
        while (this.items[index] != null && !this.__equal(e, this.items[index].data)) {
            index++;
            index = index % this.items.length;
        }

        return this.items[index] != null && !this.items[index].isDeleted;
    }

    toString() {
        let res = "HashSet2{ data = "
        for (let i = 0; i < this.items.length; i++) {
            if (this.items[i] != null) {
                res += this.items[i].toString() + ","
            }
        }
        return res + "}"
    }
}