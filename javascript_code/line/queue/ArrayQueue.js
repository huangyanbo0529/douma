

class ArrayQueue {
    constructor() {
        this.data = []
    }

    getSize() {
        return this.data.length
    }

    isEmpty() {
        return this.data.length == 0
    }

    enqueue(e) {
        // 时间复杂度：O(1)
        this.data.push(e)
    }

    dequeue(e) {
        // 删除数组第一个元素，并返回
        // 时间复杂度：O(n)
        return this.data.shift()
    }

    getFront() {
        if (this.data.length == 0) {
            throw new Error("Queue is Empty")
        }
        return this.data[0]
    }

    toString() {
        let res = "Queue：队首 ["
        for (let i = 0; i < this.data.length; i++) {
            res += this.data[i]
            if (i != this.data.length - 1) {
                res += ", "
            }
        }
        res += "]"
        return res
    }
}


const queue = new ArrayQueue()
queue.enqueue(10)
console.log(queue.toString())

queue.enqueue(20)
console.log(queue.toString())

queue.enqueue(30)
console.log(queue.toString())

queue.dequeue()
console.log(queue.toString())

queue.dequeue()
console.log(queue.toString())