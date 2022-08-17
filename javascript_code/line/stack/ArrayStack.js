
class ArrayStack {

    constructor(capacity) {
        this.data = new Array(capacity)
        this.size = 0
    }

    getSize() {
        return this.size
    }

    isEmpty() {
        return this.size == 0
    }

    push(e) {
        if (this.size == this.data.length) {
            throw new Error("push failed, Stack is full")
        }
        this.data[this.size] = e
        this.size++
    }

    pop() {
        if (this.isEmpty()) {
            throw new Error("pop failed, stack is empty")
        }
        const ret = this.data[this.size - 1]
        this.size--
        return ret
    }

    peek() {
        if (this.isEmpty()) {
            throw new Error("peek failed, stack is empty")
        }
        return this.data[this.size - 1]
    }

    toString() {
        let res = "Stack: ["
        for (let i = 0; i < this.size; i++) {
            res += this.data[i]
            if (i != this.size - 1) {
                res += ","
            }
        }
        res += "] top"
        return res
    }
}

const stack = new ArrayStack(5)
stack.push(10)
console.log(stack.toString())
stack.push(20)
console.log(stack.toString())
stack.push(30)
console.log(stack.toString())

stack.pop()
console.log(stack.toString())
stack.pop()
console.log(stack.toString())