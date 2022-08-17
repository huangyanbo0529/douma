

class Node {
    constructor(e, prev, next) {
        this.e = e
        this.prev = prev
        this.next = next
    }

    toString() {
        return this.e
    }
}

class DoubleLinkedList {
    constructor() {
        this.first = null
        this.last = null
        this.size = 0
    }

    getSize() {
        return this.size
    }

    isEmpty() {
        return this.size == 0
    }

    // 时间复杂度是 O(n)
    node(index) {
        if (index < 0 || index >= this.size) {
            return null
        }

        let curr = null
        // 如果 index 小于链表长度的一半，则从 first 开始遍历查找
        if (index < Math.floor(this.size / 2)) {
            curr = this.first
            for (let i = 0; i < index; i++) {
                curr = curr.next
            }
        } else { // 如果 index 大于等于链表长度的一半，则从 last 开始遍历查找
            curr = this.last
            for (let i = 0; i < this.size - index - 1; i++) {
                curr = curr.prev
            }
        }
        return curr
    }

    /**
     * 找到指定索引 index 所在的节点的元素值
     * @param index
     * @return
     */
    // 时间复杂度是 O(n)
    get(index) {
        const n = this.node(index)
        if (n == null) {
            throw new Error("index failed, index must >= 0 and < size")
        }
        return n.e
    }

    // 时间复杂度： O(1)
    getFirst() {
        return this.first
    }

    // 时间复杂度： O(1)
    getLast() {
        return this.last
    }

    // 时间复杂度是 O(n)
    set(index, e) {
        const n = this.node(index)
        if (n == null) {
            throw new Error("index failed, index must >= 0 and < size")
        }
        n.e = e
    }

    /**
     * 往链表的表头插入节点
     * @param e
     */
    addFirst(e) {
        const newNode = new Node(e)
        if (this.first == null) {
            // 如果头节点为空，说明链表中没有一个节点
            // 那么新插入的节点既是头节点，又是尾节点
            this.last = newNode
        } else {
            // 将新节点作为头节点
            newNode.next = this.first
            this.first.prev = newNode
        }
        this.first = newNode
        this.size++
    }

    /**
     * 往链表尾巴插入新节点
     * @param e
     */
    addLast(e) {
        const newNode = new Node(e)
        if (this.last == null) {
            // 如果尾节点为空，说明链表中没有一个节点
            // 那么新插入的节点既是头节点，又是尾节点
            this.first = newNode
        } else {
            // 将新节点作为尾节点
            newNode.prev = this.last
            this.last.next = newNode
        }
        this.last = newNode
        this.size++
    }

    /**
     * 往指定索引位置插入节点
     * @param index
     * @param e
     */
    // 时间复杂度是 O(n)
    add(index, e) {
        if (index < 0 || index > this.size) {
            throw new Error("add failed, index must >= 0 and <= size")
        }
        if (index == this.size) {
            this.addLast(e)
        } else if (index == 0) {
            this.addFirst(e)
        } else {
            // 1. 找到要插入的位置，并记住这个位置的节点
            const oldNode = this.node(index)
            const prev = oldNode.prev

            // 2. 新建节点，将它的 next 指向 oldNode，将它的 prev 指向 oldNode.prev
            const  newNode = new Node(e, prev, oldNode)

            // 3. 将新建节点设置为 oldNode 的 prev
            oldNode.prev = newNode

            // 4. 将新建节点设置 oldNode 之前的 prev 的 next
            prev.next = newNode

            this.size++
        }
    }

    removeFirst() {
        if (this.first == null) {
            throw new Error("链表是空的")
        }

        const e = this.first.e
        // 拿到头节点的下一个节点
        const next = this.first.next
        // 如果 next 为空，说明整个链表只有一个节点
        if (next == null) {
            this.first = null
            this.last = null
        } else {
            // 将头节点从链表中断开
            this.first.next = null
            next.prev = null
            // 将 next 设置为头节点
            this.first = next
        }
        this.size--
        return e
    }

    removeLast() {
        if (this.last == null) {
            throw new Error("链表是空的")
        }

        const e = this.last.e
        // 拿到尾节点的前一个节点
        const prev = this.last.prev
        // 如果 prev 为空，说明整个链表只有一个节点
        if (prev == null) {
            this.last = null
            this.first = null
        } else {
            // 将尾节点从链表中断开
            this.last.prev = null
            prev.next = null
            // 将 prev 设置为尾节点
            this.last = prev
        }
        this.size--
        return e
    }

    // 时间复杂度是 O(n)
    remove(index) {
        if (index < 0 || index >= this.size) {
            throw new Error("remove failed, index must >= 0 and < size")
        }

        if (index == 0) {
            return this.removeFirst()
        } else if (index == this.size - 1) {
            return this.removeLast()
        }

        // 1. 找到要删除的节点
        const delNode = this.node(index)
        const  e = delNode.e

        // 2. 记住要删除节点的 prev 和 next 节点
        const prev = delNode.prev
        const next = delNode.next

        // 3. 将删除节点的前后节点联系起来
        prev.next = next
        next.prev = prev

        // 4. 将删除节点从链表中断开
        delNode.next = null
        delNode.prev = null

        this.size--

        return e
    }
}