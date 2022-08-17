

// 时间复杂度：O(nlogn)
// 空间复杂度：O(1)
const sort = function (data) {
    if (data == null || data.length == 0) return

    const sortR = function (lo, hi) {
        if (lo >= hi) return
        // 分区
        let pivot = data[hi]

        let less = lo
        let great = hi

        let i = lo
        while (i <= great) {
            if (data[i] < pivot) {
                [data[less], data[i]] = [data[i], data[less]]
                less++
                i++
            } else if (data[i] > pivot) {
                [data[i], data[great]] = [data[great], data[i]]
                great--
            } else {
                i++
            }
        }
        // 对左边数组排序
        sortR(lo, less - 1) // log2n
        // 对右边数组排序
        sortR(great + 1, hi) // log2n
    }

    sortR(0, data.length - 1)
}



data = [34, 33, 12, 78, 21, 1, 98, 100]
sort(data)
console.log(data)