// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


function getNext(pattern) { // O(n^3)
    const n = pattern.length
    // bug 修复： 如果只有一个字符的话，就不计算 next 数组
    if (n == 1) return []

    const next = new Array(n - 1).fill(-1)

    for (let i = 1; i < n - 1; i++) {
        // 1. 拿到模式串中 [0...i] 这个好前缀
        const goodPrefix = pattern.substring(0, i + 1)
        // 2. 计算当前好前缀的【最长匹配前缀子串】结尾字符的下标
        for (let j = i; j > 0; j--) {
            // 2.1 拿到好前缀的 [j, i] 这个后缀字符串
            const suffix = goodPrefix.substring(j)
            // 2.2 将后缀的每个字符和好前缀的前缀的每个字符比较
            // 得到第一个不相等的字符所在的位置 k
            let k
            for (k = 0; k < suffix.length; k++) {
                if (suffix[k] != goodPrefix[k]) break
            }

            // 2.3 如果前缀匹配了后缀字符串，那么更新【最长匹配前缀字符串】结尾字符的下标
            if (k == suffix.length) {
                // 注意：next[i] 之前可能已经计算过，所以我们需要取最大值
                next[i] = Math.max(k - 1, next[i])
            }
        }
    }

    // 最值问题
    return next
}

// 最好情况下时间复杂度：O(m)
// 最坏情况下时间复杂度：O(mn)
// 空间复杂度：O(n)
function indexOf(mainStr, pattern) {
    if (!mainStr || !pattern) return -1

    const m = mainStr.length, n = pattern.length
    if (m < n) return -1

    // 根据模式串所有的前缀，计算得到 next 数组
    const next = getNext(pattern)

    let j = 0
    for (let i = 0; i < m; i++) {
        while (j > 0 && mainStr[i] != pattern[j]) {
            // 就不从头开始匹配了，直接跳到下一个最长匹配前缀字符串的结尾字符的下一个字符位置
            j = next[j - 1] + 1
        }

        if (mainStr[i] == pattern[j]) j++

        if (j == n) return i - n + 1
    }

    return -1
}

const mainStr = "aaabaaa";
const patternStr = "baaa";

console.log(indexOf(mainStr, patternStr))