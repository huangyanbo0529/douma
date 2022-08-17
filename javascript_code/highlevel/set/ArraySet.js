// 抖码算法，让算法学习变的简单有趣
// 作者：老汤

class ArraySet {
    constructor() {
        this.data = []
    }

    size() {
        return this.data.length
    }

    isEmpty() {
        return this.data.length == 0
    }

    add(e) { // O(n)
        const index = this.data.indexOf(e)
        if (index == -1) {
            this.data.push(e)
        }
    }

    remove(e) {
        const index = this.data.indexOf(e)
        if (index > -1) {
            // 删除从 index 开始的 1 个元素，其实就是删除 index 对应的元素
            this.data.splice(index, 1)
        }
    }

    contains(e) {
        return this.data.indexOf(e) > -1
    }

    toString() {
        return `ArraySet{ data = ${this.data} }`
    }
}

function test() {
    const arraySet = new ArraySet()
    arraySet.add(2)
    arraySet.add(4)
    arraySet.add(1)

    console.log(arraySet.toString())

    arraySet.add(2)
    console.log(arraySet.toString())

    console.log(arraySet.contains(4))

    arraySet.remove(1)
    console.log(arraySet.toString())
}

test()