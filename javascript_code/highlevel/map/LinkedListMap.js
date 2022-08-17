// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


class Node {
    constructor(key, value, next) {
        this.key = key
        this.value = value
        this.next = (next == undefined ? null : next)
    }

    toString() {
        return `${this.key} -> ${this.value}`
    }
}

export class LinkedListMap {
    constructor(__equal) {
        this.dummyHead = new Node()
        this.__size = 0
        this.__equal = __equal
    }

    size() {
        return this.__size;
    }

    isEmpty() {
        return this.__size == 0;
    }

    add(key, value) { // O(n)
        // 1. 找到 key 对应的 value 所在的节点
        const curr = this.getNode(key);

        // 2. 如果 curr 为空的话，说明 Map 中还没有这个键值对
        if (curr == null) {
            // 直接将键值对插入头节点即可
            this.dummyHead.next = new Node(key, value, this.dummyHead.next);
            this.__size++;
        } else {
            // 键值对已经存在，那么更新 value
            curr.value = value;
        }
    }

    getNode(key) { // O(n)
        let curr = this.dummyHead.next
        while (curr) {
            if (this.__equal(key, curr.key)) {
                break
            }
            curr = curr.next
        }
        return curr
    }

    remove(key) { // O(n)
        // 1. 找到需要删除的节点的前一个节点
        let prev = this.dummyHead;
        let curr = this.dummyHead.next;
        while (curr) {
            if (this.__equal(key, curr.key)) {
                break;
            }
            prev = curr;
            curr = curr.next;
        }

        // 2. 如果需要删除的节点不为空，则删除节点，并返回删除节点的值
        if (curr) {
            prev.next = curr.next;
            curr.next = null;
            this.__size--;
            return curr.value;
        }
        return null;
    }

    set(key, newValue) {
        // 1. 找到 key 对应的 value 所在的节点
        const curr = this.getNode(key);

        if (curr != null) curr.value = newValue;
        else throw new Error("没有对应的 key ：" + key);
    }

    get(key) {
        const node = this.getNode(key)
        return node == null ? null : node.value
    }

    containsKey(key) { // O(n)
        const node = this.getNode(key)
        // 如果 node 不为 null ，则表示存在，否则表述不存在
        return node != null
    }
}