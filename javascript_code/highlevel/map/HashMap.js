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

export class HashMap {
    constructor( __hash, __equal, initCapacity, loadFactor) {
        this.loadFactor = (loadFactor == undefined ? 0.75 : loadFactor)

        this.data = new Array(initCapacity).fill(null)
        this.__size = 0
        this.__hash = __hash
        this.__equal = __equal
    }

    // 计算一个 key 对应的索引值
    hash(key, len) {
        return Math.abs(this.__hash(key) % len)
    }

    size() {
        return this.__size;
    }

    isEmpty() {
        return this.__size == 0;
    }

    add(key, value) {
        const index = this.hash(key, this.data.length);
        const curr = this.getNode(key, index);
        if (curr == null) {
            this.data[index] = new Node(key, value, this.data[index]);
            this.__size++;
            if (this.__size >= this.data.length * this.loadFactor) {
                this.resize(2 * this.data.length);
            }
        } else {
            curr.value = value;
        }
    }

    getNode(key, index) {
        let curr = this.data[index];
        while (curr) {
            if (this.__equal(key, curr.key)) {
                break;
            }
            curr = curr.next;
        }
        return curr;
    }

    resize(newCapacity) {
        const newData = new Array(newCapacity).fill(null);
        for (let i = 0; i < this.data.length; i++) {
            let curr = this.data[i];
            while (curr) {
                const key = curr.key;
                const newIndex = this.hash(key, newCapacity);
                const head = newData[newIndex];
                newData[newIndex] = new Node(key, curr.value);
                if (head != null) {
                    newData[newIndex].next = head;
                }
                curr = curr.next;
            }
        }
        this.data = newData;
    }

    remove(key) { // O(n)
        const index = this.hash(key, this.data.length);
        if (this.data[index] == null) {
            return null;
        }
        let prev = null;
        let curr = this.data[index];
        while (curr) {
            if (this.__equal(key, curr,key)) {
                if (prev == null) {
                    // 删除头节点
                    this.data[index] = curr.next;
                } else {
                    prev.next = curr.next;
                }
                curr.next = null;
                this.__size--;
                return curr.value;
            }
            prev = curr;
            curr = curr.next;
        }
        return null;
    }

    set(key, newValue) {
        const index = this.hash(key, this.data.length);
        const curr = this.getNode(key, index);

        if (curr != null) curr.value = newValue;
        else throw new Error("没有对应的 key ：" + key);
    }

    get(key) {
        const index = this.hash(key, this.data.length);
        const node = this.getNode(key, index)
        return node == null ? null : node.value
    }

    containsKey(key) { // O(n)
        const index = this.hash(key, this.data.length);
        const node = this.getNode(key, index)
        // 如果 node 不为 null ，则表示存在，否则表述不存在
        return node != null
    }
}