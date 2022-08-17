// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


class FIFOCache {
    constructor(capacity) {
        this.cache = new Map()
        this.queue = []
        this.capacity = capacity
    }

    get(key) {
        return this.cache.get(key)
    }

    put(key, value) {
        if (!this.cache.has(key)) {
            if (this.cache.size == this.capacity) {
                const oldKey = this.queue.shift()
                this.cache.delete(oldKey)
            }
            this.queue.push(key)
        }
        this.cache.set(key, value)
    }
}

function test() {
    const cache = new FIFOCache(3)
    cache.put(1, 1)
    cache.put(2, 2)
    cache.put(3, 3)
    cache.put(4, 4)
    console.log(cache.get(3))
    cache.put(4, 5)
    console.log(cache.get(4))
    cache.put(5, 6)
    console.log(cache.get(2))
}

test()