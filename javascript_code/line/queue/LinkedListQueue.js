

export class LinkedListQueue {
    constructor(linkedList) {
        this.data = linkedList
    }

    getSize() {
        return this.data.getSize()
    }

    isEmpty() {
        return this.data.isEmpty()
    }

    enqueue(e) {
        // 时间复杂度： O(n)
        this.data.addLast(e)
    }

    dequeue() {
        return this.data.removeFirst()
    }

    getFront() {
        return this.data.getFirst()
    }

    toString() {
        let res = "Queue：队首 ["
        for (let i = 0; i < this.data.getSize(); i++) {
            res += this.data.get(i)
            if (i != this.data.getSize() - 1) {
                res += ", "
            }
        }
        res += "]"
        return res
    }
}
