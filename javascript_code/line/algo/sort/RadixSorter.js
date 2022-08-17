const sort = function (data) {
    if (data == null || data.length == 0) return

    // 1. 找到最大值  4006869915
    let max = data[0]
    for (let i = 1; i < data.length; i++) {
        max = Math.max(max, data[i])
    }

    // 2. 对数组按照每个元素的每位进行计数排序
    for (let exp = 1; Math.floor(max / exp) > 0; exp *= 10) { // O(n)
        countSort(data, exp) // 时间复杂度：O(n)
    }
}

// 时间复杂度：O(n)
const countSort = function (data, exp) {
    // 之所以是 10，是因为数字只有 0...9 十个数字
    const count = new Array(10).fill(0);

    for (let i = 0; i < data.length; i++) {
        // 个位数： (234 / 1) % 10 = 4
        // 十位数： (234 / 10) % 10 = 3
        // 百位数： (234 / 100) % 10 = 2
        const digit = (Math.floor(data[i] / exp)) % 10
        count[digit]++
    }

    for (let i = 1; i < 10; i++) {
        count[i] += count[i - 1]
    }

    const output = new Array(data.length).fill(0)
    for (let i = data.length - 1; i >= 0; i--) {
        const digit = (Math.floor(data[i] / exp)) % 10
        const k = count[digit] - 1
        output[k] = data[i]
        count[digit]--
    }

    for (let i = 0; i < data.length; i++) {
        data[i] = output[i]
    }
}

data = [4512, 4231, 31923, 2165, 1141]
sort(data)
console.log(data)