

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
const sort = function (data) {
    if (data == null || data.length == 0) return

    for (let round = 1; round <= data.length; round++) { // 控制冒泡轮数
        let hasSwap = false
        const compareTimes = data.length - round
        for (let i = 0; i < compareTimes; i++) { // 控制每轮比较次数
            if (data[i] > data[i + 1]) {
                [data[i], data[i + 1]] = [data[i + 1], data[i]]
                hasSwap = true
            }
        }
        if (!hasSwap) break
    }
}

data = [12, 23, 36, 9, 24, 42]
sort(data)
console.log(data)