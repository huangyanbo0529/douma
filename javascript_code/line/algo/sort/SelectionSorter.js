

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
const sort = function (data) {
    if (data == null || data.length == 0) return
    for (let i = 0; i < data.length; i++) { // 控制选择排序的轮数
        // 找到 [i, n) 中的最小元素所在的索引
        let minNumIndex = i
        for (let j = i + 1; j < data.length; j++) {
            if (data[j] < data[minNumIndex]) {
                minNumIndex = j
            }
        }
        // 将 data[i] 和最小元素进行交换
        [data[i], data[minNumIndex]] = [data[minNumIndex], data[i]]
    }
}

data = [12, 23, 36, 9, 24, 42]
sort(data)
console.log(data)