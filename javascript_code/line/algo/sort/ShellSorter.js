

const sort = function (data) {
    if (data == null || data.length == 0) return

    // 1. 计算递增序列
    const n = data.length
    const list = []
    let k = 1
    let h
    do {
        h = Math.floor((Math.pow(3, k) - 1) / 2)
        // bug 修复：需要考虑 n < 3 的场景，
        // 当 n < 3 的时候，不应该 break，而应该将 h 添加到 list 中
        if (h > Math.floor(n / 3) && n >= 3) break
        list.push(h) // 1, 4, 13, 40, 121......
        k++
    } while (h <= Math.floor(n / 3))

    // 2. 希尔排序
    for (let k = list.length - 1; k >= 0; k--) { // 倒序遍历
        h = list[k]
        // 将数组变为 h 有序
        for (let i = h; i < n; i++) {
            for (let j = i; j >= h; j = j - h) {
                if (data[j] < data[j - h]) {
                    [data[j], data[j - h]] = [data[j - h], data[j]]
                } else {
                    break
                }
            }
        }
    }
}

const sort1 = function (data) {
    if (data == null || data.length == 0) return

    // 1. 计算递增序列
    const n = data.length
    let h = 1
    while (h < Math.floor(n / 3)) h = 3 * h + 1 // 1, 4, 13, 40, 121......

    // 2. 希尔排序
    while (h >= 1) {
        // 将数组变为 h 有序
        for (let i = h; i < n; i++) {
            for (let j = i; j >= h; j = j - h) {
                if (data[j] < data[j - h]) {
                    [data[j], data[j - h]] = [data[j - h], data[j]]
                } else {
                    break
                }
            }
        }
        h = Math.floor(h / 3)
    }
}

data = [2, 5, 1, 23, 22, 33, 56, 12, 5, 3, 5, 6, 8, 2, 3, 4]
sort(data)
console.log(data)