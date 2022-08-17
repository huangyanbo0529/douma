

class LoopQueue {
    constructor(capacity) {
        this.data = new Array(capacity)
        this.head = 0
        this.tail = 0
        this.size = 0
    }

    getCapacity() {
        return this.data.length - 1
    }

    getSize() {
        return this.size
    }

    enqueue(e) {
        // 这里也可以使用 size 来判断队列是否满了，参考 issue ：https://gitee.com/douma_edu/douma-algo/issues/I4WGCE
        if ((this.tail + 1) % this.data.length == this.head) {
            // 队列满了
            this.resize(this.getCapacity() * 2)
        }
        this.data[this.tail] = e
        this.size++
        this.tail = (this.tail + 1) % this.data.length
    }

    dequeue(e) {
        if (this.isEmpty()) {
            throw new Error("dequeue error, No Element for dequeue")
        }
        const res = this.data[this.head]
        this.data[this.head] = null
        this.size--
        this.head = (this.head + 1) % this.data.length
        if (this.size == Math.floor(this.getCapacity() / 4)) {
            this.resize(Math.floor(this.getCapacity() / 2))
        }
        return res
    }

    resize(newCapacity) {
        const newData = new Array(newCapacity + 1)
        for (let i = 0; i < this.size; i++) {
            newData[i] = this.data[(i + this.head) % this.data.length]
        }
        this.data = newData
        this.head = 0
        this.tail = this.size
    }

    getFront() {
        if (this.isEmpty()) {
            throw new Error("Queue is Empty")
        }
        return this.data[this.head]
    }

    isEmpty() {
        // 这里也可以使用 size 来判断队列是否空的，参考 issue ：https://gitee.com/douma_edu/douma-algo/issues/I4WGCE
        return this.head == this.tail
    }

    toString() {
        let res = `Queue：size = ${this.size}, capacity = ${this.getCapacity()}\n`
        res += " 队首 ["
        for (let i = this.head; i != this.tail; i = (i + 1) % this.data.length) {
            res += this.data[i]
            if ((i + 1) % this.data.length != this.tail) {
                res += ", "
            }
        }
        res += "]"
        return res
    }
}


const queue = new LoopQueue(10)
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