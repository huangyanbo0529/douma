
class Node {
    constructor(e, next) {
        this.e = e
        this.next = next
    }

    toString() {
        return this.e
    }
}

class LinkedListQueue2 {
    constructor(linkedList) {
        this.head = null
        this.tail = null
        this.size = 0
    }

    getSize() {
        return this.size
    }

    isEmpty() {
        return this.size == 0
    }

    enqueue(e) {
        const newNode = new Node(e)
        if (this.tail == null) {
            this.tail = newNode
            this.head = this.tail
        } else {
            this.tail.next = newNode
            this.tail = newNode
        }
        this.size++
    }

    dequeue(e) {
        if (this.isEmpty()) {
            throw new Error("dequeue error, no element")
        }
        const delNode = this.head
        this.head = this.head.next
        delNode.next = null

        if (this.head == null) {
            this.tail = null
        }
        this.size--
        return delNode.e
    }

    getFront() {
        if (this.isEmpty()) {
            throw new Error("getFront error, no element")
        }
        return this.head.e
    }

    toString() {
        let res = "Queue：队首 ["
        let curr = this.head
        while (curr != null) {
            res += curr.toString() + "=>"
            curr = curr.next
        }
        res += "null]"
        return res
    }
}


const queue = new LinkedListQueue2()
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