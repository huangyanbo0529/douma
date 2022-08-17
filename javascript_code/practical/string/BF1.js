// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


// 时间复杂度：O(mn)
// 空间复杂度：O(1)
function indexOf(mainStr, pattern) {
    if (!mainStr || !pattern) return -1

    const m = mainStr.length, n = pattern.length
    if (m < n) return -1

    for (let i = 0; i < m; i++) {
        // 1. 比对后面的字符，如果相等的话，一直比对下去
        let k = i;
        for (let j = 0; j < n; j++) {
            if (k < m && pattern[j] == mainStr[k]) {
                k++
                // 2. 如果 j 是模式串的最后一个字符，说明匹配到了模式串
                if (j == n - 1) return i
            } else {
                break
            }
        }
    }

    return -1
}

const mainStr = "    your code";
const patternStr = "your";

console.log(indexOf(mainStr, patternStr))