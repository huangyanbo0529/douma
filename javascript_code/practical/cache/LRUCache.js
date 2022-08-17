// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


class Node {
    constructor() {
        this.key = 0;
        this.value = 0;
        this.prev = null;
        this.next = null;
    }
}

class LRUCache {
    constructor(capacity) {
        this.cache = new Map()
        this.capacity = capacity
        this.head = new Node()
        this.tail = new Node()
        this.head.next = this.tail
        this.tail.prev = this.head
    }

    addNodeToHead(node) {
        node.next = this.head.next;
        this.head.next.prev = node;

        this.head.next = node;
        node.prev = this.head;
    }

    removeNode(node) {
        const prevNode = node.prev;
        const nextNode = node.next;

        prevNode.next = nextNode;
        nextNode.prev = prevNode;

        node.prev = null;
        node.next = null;
    }

    moveNodeToHead(node) {
        this.removeNode(node)
        this.addNodeToHead(node)
    }

    get(key) {
        if (!this.cache.has(key)) return undefined
        const node = this.cache.get(key)
        this.moveNodeToHead(node)
        return node.value
    }

    removeTailNode() {
        const delNode = this.tail.prev
        this.removeNode(delNode)
        return delNode
    }

    put(key, value) {
        if (!this.cache.has(key)) {
            if (this.cache.size == this.capacity) {
                const delNode = this.removeTailNode()
                this.cache.delete(delNode.key)
            }

            const node = new Node()
            node.key = key
            node.value = value

            this.cache.set(key, node)
            this.addNodeToHead(node)

        } else {
            const node = this.cache.get(key)
            node.value = value

            this.moveNodeToHead(node)
        }
    }
}

function test() {
    const cache = new LRUCache(3)
    cache.put(1, 1)
    cache.put(2, 2)
    cache.put(3, 3)
    cache.put(4, 4)
    console.log(cache.get(3))
    cache.put(2, 5)
    cache.put(5, 6)
    console.log(cache.get(4))
}

test()