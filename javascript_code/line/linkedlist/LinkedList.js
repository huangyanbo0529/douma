

class Node {
    constructor(e, next) {
        this.e = e
        this.next = next
    }

    toString() {
        return this.e
    }
}

export class LinkedList {

    constructor() {
        this.dummyHead = new Node(-1)
        this.size = 0
    }

    getSize() {
        return this.size
    }

    isEmpty() {
        return this.size == 0
    }

    /**
     * 查询指定索引的节点的值
     * @param index
     * @return
     */
    // 时间复杂度： O(n)
    get(index) {
        if (index < 0 || index >= this.size) {
            throw new Error("get failed, index must >= 0 and < size")
        }
        let curr = this.dummyHead.next
        for (let i = 0; i < index; i++) {
            curr = curr.next
        }
        return curr.e
    }

    // 时间复杂度： O(1)
    getFirst() {
        return this.get(0)
    }

    // 时间复杂度： O(n)
    getLast() {
        return this.get(this.size - 1)
    }

    /**
     * 修改指定索引的节点元素
     * @param index
     * @param e
     */
    // 时间复杂度： O(n)
    set(index, e) {
        if (index < 0 || index >= this.size) {
            throw new Error("set failed, index must >= 0 and < size")
        }
        let curr = this.dummyHead.next
        for (let i = 0; i < index; i++) {
            curr = curr.next
        }
        curr.e = e
    }


    /**
     * 在指定索引的位置插入新的节点
     * @param index 需要插入的位置
     * @param e 需要插入的数据
     */
    // 时间复杂度： O(n)
    add(index, e) {
        if (index < 0 || index > this.size) {
            throw new Error("add failed, index must >= 0 and <= size")
        }
        let prev = this.dummyHead
        for (let i = 0; i < index; i++) {
            prev = prev.next
        }
        prev.next = new Node(e, prev.next)
        this.size++
    }

    // 时间复杂度： O(1)
    addFirst(e) {
        return this.add(0, e)
    }

    // 时间复杂度： O(n)
    addLast(e) {
        return this.add(this.size, e)
    }


    /**
     * 删除指定索引的节点，并返回删除的节点的值
     * @param index
     * @return
     */
    // 时间复杂度： O(n)
    remove(index) {
        if (index < 0 || index >= this.size) {
            throw new Error("remove failed, index must >= 0 and < size")
        }

        let prev = this.dummyHead
        for (let i = 0; i < index; i++) {
            prev = prev.next
        }

        const delNode = prev.next
        prev.next = delNode.next
        delNode.next = null

        this.size--

        return delNode.e
    }

    // 时间复杂度： O(1)
    removeFirst() {
        return this.remove(0)
    }

    // 时间复杂度： O(n)
    removeLast() {
        return this.remove(this.size - 1)
    }

    /**
     * 删除第一个值等于 e 的节点
     * @param e
     */
    removeElement(e) {
        if (this.dummyHead.next == null) {
            throw new Error("removeElement failed, LinkedList is Empty")
        }

        let prev = this.dummyHead
        let curr = this.dummyHead.next
        while (curr != null) {
            if (curr.e == e) {
                break
            }
            prev = curr
            curr = curr.next
        }

        // bug 修复，需要先判断 curr
        // 如果 curr 为 null 的话，说明链表中不存在值等于 e 的节点
        if (curr != null) {
            prev.next = curr.next
            curr.next = null
        }
    }

    /**
     * 判断链表中是否存在指定元素
     * @param e
     * @return
     */
    // 时间复杂度： O(n)
    contains(e) {
        let curr = this.dummyHead
        while (curr != null) {
            if (curr.e == e) {
                return true
            }
            curr = curr.next
        }
        return false
    }

    toString() {
        let res = ""
        let curr = this.dummyHead.next
        while (curr != null) {
            res += curr.toString() + "=>"
            curr = curr.next
        }
        res += "null"
        return res
    }
}


// 运行这个单元测试的时候，需要去掉上面的 export 关键字
// 测试
const linkedList = new LinkedList()
linkedList.addLast(5)
console.log(linkedList.toString())

linkedList.addFirst(10)
console.log(linkedList.toString())

linkedList.add(2, 34)
console.log(linkedList.toString())

console.log(linkedList.get(1))

linkedList.addFirst(50)
console.log(linkedList.toString())

linkedList.remove(2)
console.log(linkedList.toString())

linkedList.removeFirst()
console.log(linkedList.toString())