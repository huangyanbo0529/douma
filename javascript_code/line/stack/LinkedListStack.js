
class LinkedListStack {

    constructor(linkedList) {
        this.linkedList = linkedList
    }

    getSize() {
        return this.linkedList.getSize()
    }

    isEmpty() {
        return this.linkedList.isEmpty()
    }

    push(e) {
        this.linkedList.addFirst(e)
    }

    pop() {
        return this.linkedList.removeFirst()
    }

    peek() {
        return this.linkedList.getFirst()
    }

    toString() {
        let res = "Stack: ["
        for (let i = this.linkedList.getSize() - 1; i >= 0; i--) {
            res += this.linkedList.get(i)
            if (i != 0) {
                res += ","
            }
        }
        res += "] top"
        return res
    }
}