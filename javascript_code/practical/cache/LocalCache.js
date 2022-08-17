// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


class LocalCache {
    constructor() {
        this.cache = new Map()
    }

    get(key) {
        return this.cache.get(key)
    }

    put(key, value) {
        this.cache.set(key, value)
    }
}