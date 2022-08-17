

// js 的数组可以当成栈来使用
class DynamicArrayStack {

    constructor() {
        // js 的数组本来就是动态数组
        this.data = []
    }

    getSize() {
        return this.data.length
    }

    isEmpty() {
        return this.data.length == 0
    }

    push(e) {
        this.data.push(e)
    }

    pop() {
        return this.data.pop()
    }

    peek() {
        return this.data[this.data.length]
    }

    toString() {
        let res = "Stack: ["
        for (let i = 0; i < this.data.length; i++) {
            res += this.data[i]
            if (i != this.data.length - 1) {
                res += ","
            }
        }
        res += "] top"
        return res
    }
}

const stack = new DynamicArrayStack(5)
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