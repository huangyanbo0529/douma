// 抖码算法，让算法学习变的简单有趣
// 作者：老汤

class BitMap {
    constructor() {
        this.b = 0
    }

    set(num) {
        /*
            set 2
            00000001 << 2
            00000100
          | 00000000
          = 00000100

            set 2
            00000001 << 2
            00000100
          | 00000100
          = 00000100
         */
        this.b |= (1 << num)
    }

    contains(target) {
        /*
            contains 4
            00000001 << 4
            00010000
          & 10101100
          = 00000000
         */
        // 10101100
        return ((1 << target) & this.b) != 0
    }

    toString() {
        return `BitMap{ b = ${this.b.toString(2)} }`
    }
}

const data = [2, 7, 2, 5, 3]
const target = 2

const bitmap = new BitMap()
for (let i = 0; i < data.length; i++) {
    bitmap.set(data[i])
}

console.log(bitmap.toString())

if (bitmap.contains(target)) {
    console.log("存在目标值：" + target)
}