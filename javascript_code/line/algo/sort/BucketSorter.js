
// 时间复杂度：O(nlogn)
// 空间复杂度：O(1)
const quickSort = function (data) {
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

const sort = function (data) {
    if (data == null || data.length == 0) return

    // 1. 创建几个空的 bucket
    let maxValue = data[0];
    for (const d of data) {
        maxValue = Math.max(maxValue, d)
    }
    /*
    这里为什么是除以 10 呢？
    在视频中，我们讲过，假设数组中的元素的大小是 0 到 39
    然后我们想划分成 4 个桶，所以 39 / 10 + 1 = 4

    这里需要注意的是：bucketNum 的计算是根据场景确定的，不同的场景 bucketNum 的计算方式是不同的
    所以 bucketNum 的计算之前，需要确定桶排序使用的场景
     */
    const bucketNum = Math.floor(maxValue / 10) + 1 // 39 / 10 + 1 = 4
    const buckets = new Array(bucketNum)

    // 2. 将所有的元素添加进对应的 bucket
    for (let i = 0; i < data.length; i++) {
        // 计算当前元素应该被分配到哪一个桶里
        const index = Math.floor(data[i] / 10)
        if (buckets[index] == null) {
            buckets[index] = [];
        }
        buckets[index].push(data[i])
    }

    // 3. 对每一个 bucket 中的元素进行排序
    for (let i = 0; i < bucketNum; i++) {
        const bucketData = buckets[i]
        if (bucketData != null) {
            quickSort(bucketData)
        }
    }

    // 4. 从 buckets 中拿到排序后的数组
    let index = 0
    for (let i = 0; i < bucketNum; i++) {
        const bucketData = buckets[i]
        if (bucketData != null) {
            for (let j = 0; j < bucketData.length; j++) {
                data[index++] = bucketData[j]
            }
        }
    }
}

data = [2, 5, 1, 23, 22, 33, 56, 12, 5, 3, 5, 6, 8, 2, 3, 4]
sort(data)
console.log(data)