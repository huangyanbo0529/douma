// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


class Node {
    constructor(e, next) {
        this.e = e
        this.next = (next == undefined ? null : next)
    }
}

// 单元测试见 Set 集合测试页面.html
export class HashSet3 {
    constructor(__hash, __equal, loadFactor) {
        this.data = new Array(10).fill(null)
        this.__size = 0
        this.__hash = __hash
        this.__equal = __equal
        this.loadFactor = (loadFactor == undefined ? 0.75 : loadFactor)
    }

    hash(e, len) {
        return Math.abs(this.__hash(e)) % len
    }

    size() {
        return this.__size
    }

    isEmpty() {
        return this.__size == 0
    }

    add(e) { // O(1)
        const index = this.hash(e, this.data.length)
        if (this.data[index] == null) {
            this.data[index] = new Node(e);
        } else {
            let prev = null;
            let curr = this.data[index];
            while (curr) {
                if (this.__equal(e, curr.e)) {
                    return;
                }
                prev = curr;
                curr = curr.next;
            }
            prev.next = new Node(e);
        }
        this.__size++;
        if (this.__size >= this.data.length * this.loadFactor) {
            this.resize(2 * data.length);
        }
    }

    resize(newCapacity) {
        const newData = new Array(newCapacity).fill(null)
        for (let i = 0; i < this.data.length; i++) {
            const curr = this.data[i];
            while (curr) {
                const e = curr.e;
                const newIndex = this.hash(e, newCapacity);
                const head = newData[newIndex];
                newData[newIndex] = new Node(e);
                if (head != null) {
                    newData[newIndex].next = head;
                }
                // bug 修复：curr 需要往前移动
                curr = curr.next;
            }
        }
        this.data = newData
    }

    remove(e) { // O(1)
        const index = this.hash(e, this.data.length)
        if (this.data[index] == null) {
            return;
        }
        let prev = null;
        let curr = this.data[index];
        while (curr) {
            if (this.__equal(e, curr.e)) {
                if (prev == null) {
                    // 删除头节点
                    this.data[index] = curr.next;
                } else {
                    prev.next = curr.next;
                }
                curr.next = null;
                this.__size--;
                break;
            }
            prev = curr;
            curr = curr.next;
        }
    }

    contains(e) {
        const index = this.hash(e, this.data.length)
        if (this.data[index] == null) return false;
        let curr = this.data[index];
        while (curr) {
            if (this.__equal(e, curr.e)) {
                return true;
            }
            curr = curr.next;
        }
        return false;
    }

    toString() {
        let res = "HashSet3{ data = "
        for (let i = 0; i < this.data.length; i++) {
            if (this.data[i] != null) {
                let curr = this.data[i]
                while (curr) {
                    res += curr.e + "=>"
                    curr = curr.next
                }
                res += ", "
            }
        }
        return res + "}"
    }
}