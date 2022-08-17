// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


class Node {
    constructor(key, value, count) {
        this.key = key;
        this.value = value
        this.count = count
        this.prev = null;
        this.next = null;
    }
}

// 因为 js 中没有内置的 LinkedHashSet
// 所以我们需要手写一个双向链表来实现 LFUCache
class DoubleLinkedList {
    constructor() {
        this.head = new Node()
        this.tail = new Node()
        this.head.next = this.tail
        this.tail.prev = this.head
    }

    remove(node) {
        node.prev.next = node.next
        node.next.prev = node.prev
        node.prev = null
        node.next = null
        return node
    }

    // 将 node 拼接到表尾
    append(node){
        node.prev = this.tail.prev
        this.tail.prev.next = node
        node.next = this.tail
        this.tail.prev = node
    }


    popFirst() {
        if (this.head.next == this.tail)
            return null
        return this.remove(this.head.next)
    }


    isEmpty() {
        return this.head.next == this.tail
    }

}

class LFUCache {
    constructor(capacity) {
        this.keyToNode = new Map()
        this.usedCountToKeys = new Map()
        this.capacity = capacity
        this.minUsedCount = 0
    }

    get(key) {
        if (this.capacity == 0) return undefined
        if (this.keyToNode.has(key)) {
            const node = this.keyToNode.get(key)

            // 维护这个 key 对应的 count
            const usedCount = node.count

            // 1. 从这个 key 目前对应的 count 的集合中删除掉这个 key
            this.usedCountToKeys.get(usedCount).remove(node)

            // 2. 更新最小使用的次数
            // 如果当前的 usedCount 等于最小次数，
            // 并且当前的 usedCount 没有的 key，那么将最小次数加 1
            if (usedCount == this.minUsedCount
                && this.usedCountToKeys.get(usedCount).isEmpty()) {
                this.minUsedCount++;
            }

            // 3. 将 key 记录到 usedCount + 1 中的集合中
            const count = usedCount + 1
            node.count = count
            if (!this.usedCountToKeys.has(count)) {
                this.usedCountToKeys.set(count, new DoubleLinkedList())
            }
            this.usedCountToKeys.get(count).append(node)

            return node.value
        } else {
            return undefined;
        }
    }

    put(key, value) {
        if (this.capacity == 0) return undefined
        if (this.keyToNode.has(key)) {
            const node = this.keyToNode.get(key)
            node.value = value;
            // 更新 key 对应的 value 值
            this.keyToNode.set(key, node)
            // 更新 key 对应的 count 值
            this.get(key)
            return
        }
        if (this.keyToNode.size == this.capacity) {
            // 删除最少使用的 key
            const removeNode = this.usedCountToKeys.get(this.minUsedCount).popFirst()
            this.keyToNode.delete(removeNode.key)
        }
        // 新增一个缓存中不存在的 key
        const node = new Node(key, value, 1)
        this.keyToNode.set(key, node)

        // 将 key 记录到 minUsedCount 中的集合中
        this.minUsedCount = 1
        if (!this.usedCountToKeys.has(this.minUsedCount)) {
            this.usedCountToKeys.set(this.minUsedCount, new DoubleLinkedList())
        }
        this.usedCountToKeys.get(this.minUsedCount).append(node)
    }
}

function test() {
    const cache = new LFUCache(3)
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