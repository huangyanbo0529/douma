

const sort = function (data) {
    if (data == null || data.length == 0) return

    // 1. 找到数组中的最大值，初始化计数器
    let max = data[0]
    let min = data[0]
    for (let i = 1; i < data.length; i++) { // O(n)
        max = Math.max(max, data[i])
        min = Math.min(min, data[i])
    }
    const count = new Array(max - min + 1).fill(0)

    // 2. 计数
    for (let i = 0; i < data.length; i++) { // O(n)
        count[data[i] - min]++
    }

    // 3. 计数累加
    for (let i = 1; i < count.length; i++) { // O(k)
        count[i] += count[i - 1]
    }

    // 4. 计算每个元素在排序数组中的位置
    const output = new Array(data.length).fill(0);
    for (let i = data.length - 1; i >= 0; i--) { // O(n)
        const j = data[i]
        const k = count[j - min] - 1
        output[k] = data[i]

        count[j - min]--
    }

    // 5. 拷贝数组
    for (let i = 0; i < data.length; i++) { // O(n)
        data[i] = output[i]
    }
}

data = [4, 2, -2, 8, 3, 3, 1]
sort(data)
console.log(data)