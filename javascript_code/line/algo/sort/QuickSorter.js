

// 时间复杂度：O(nlogn)
// 空间复杂度：O(1)
const sort = function (data) {
    if (data == null || data.length == 0) return

    const sortR = function (lo, hi) {
        if (lo >= hi) return
        // 分区
        const j = partition(lo, hi)
        // 对左边数组排序
        sortR(lo, j - 1) // log2n
        // 对右边数组排序
        sortR(j + 1, hi) // log2n
    }

    const partition = function (lo, hi) {
        const pivot = data[hi]
        let less = lo
        let great = lo
        for (; great <= hi - 1; great++) {
            if (data[great] < pivot) {
                [data[less], data[great]] = [data[great], data[less]]
                less++
            }
        }

        [data[less], data[hi]] = [data[hi], data[less]]
        return less
    }

    sortR(0, data.length - 1)
}



data = [34, 33, 12, 78, 21, 1, 98, 100]
sort(data)
console.log(data)