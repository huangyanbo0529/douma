

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
const sort = function (data) {
    if (data == null || data.length == 0) return
    // 插入排序的轮数
    for (let i = 1; i < data.length; i++) {
        const tmp = data[i]
        let j;
        for (j = i; j > 0; j--) {
            if (tmp < data[j - 1]) {
                // 将较大的元素总是向右移动
                data[j] = data[j - 1]
            } else {
                break
            }
        }
        // 找到 i 对应的元素需要插入的位置
        data[j] = tmp
    }
}

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
const sort1 = function (data) {
    if (data == null || data.length == 0) return
    // 插入排序的轮数
    for (let i = 1; i < data.length; i++) {
        for (let j = i; j > 0; j--) {
            if (data[j] < data[j - 1]) {
                [data[j], data[j - 1]] = [data[j - 1], data[j]]
            } else {
                break
            }
        }
    }
}

data = [12, 23, 36, 9, 24, 42]
sort(data)
console.log(data)
