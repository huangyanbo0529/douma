// 抖码算法，让算法学习变的简单有趣
// 作者：老汤

class BitMap {
    constructor(nBits) {
        this.nBits = nBits
        this.bytes = new Array(Math.floor(nBits / 8 + 1))
    }

    set(num) {
        if (num > this.nBits) return
        // 找到第几个字节
        const byteIndex = num / 8
        // 找到第几位
        const bitIndex = num % 8
        this.bytes[byteIndex] |= (1 << bitIndex)
    }

    contains(target) {
        if (target > this.nBits) return false
        // 找到第几个字节
        const byteIndex = target / 8
        // 找到第几位
        const bitIndex = target % 8
        return ((1 << bitIndex) & this.bytes[byteIndex]) != 0
    }

}

const data = [2, 7, 2, 5, 3]
const target = 1

const bitmap = new BitMap(8)
for (let i = 0; i < data.length; i++) {
    bitmap.set(data[i])
}

if (bitmap.contains(target)) {
    console.log("存在目标值：" + target)
}