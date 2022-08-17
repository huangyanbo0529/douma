// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


function getNext(pattern) { // O(n^3)
    const n = pattern.length
    // bug 修复： 如果只有一个字符的话，就不计算 next 数组
    if (n == 1) return []

    const next = new Array(n - 1).fill(0)
    next[0] = -1

    for (let j = 1; j < n - 1; j++) {
        if (pattern[next[j - 1] + 1] == pattern[j]) {
            next[j] = next[j - 1] + 1
        } else {
            let pre = next[j - 1]
            while (pre >= 0 && pattern[pre + 1] != pattern[j]) {
                // 看前一个【最长匹配前缀字符串】
                pre = next[pre]
            }

            if (pattern[pre + 1] == pattern[j]) {
                next[j] = pre + 1
            } else {
                next[j] = pre
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