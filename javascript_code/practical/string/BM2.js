// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


function genBadCharIndexMap(pattern) {
    const bc = new Map()
    for (let i = 0; i < pattern.length; i++) {
        bc.set(pattern[i], i)
    }
    return bc
}

function genGoodSuffixArr(pattern, suffix, prefix) {
    const n = pattern.length
    for (let i = 0; i < n - 1; i++) {
        let j = i, k = 0
        while (j >= 0 && pattern[j] == pattern[n - 1 - k]) {
            k++
            suffix[k] = j
            j--
        }
        if (j == -1) prefix[k] = true
    }
}

// y 表示坏字符对应的模式串中的字符位置
function calMoveSteps(y, n, suffix, prefix) {
    // k 表示好后缀的长度
    const k = n - y - 1
    // 看看模式串中是否存在好后缀(第二种情况)
    if (suffix[k] != -1) return y - suffix[k] + 1
    // 看看好后缀的后缀子串是否和模式串的前缀子串匹配(第三种情况)
    for (let i = y + 1; i < n; i++) {
        if (prefix[n - i]) return i
    }
    // 将整个模式串后移 n 位(第一种情况)
    return n
}

// 时间复杂度：
// 最坏情况下，BM 算法的比较次数上限是 5m ：http://dl.acm.org/citation.cfm?id=1382431.1382552
// 最坏情况下，BM 算法的比较次数上限是 3m ：http://dl.acm.org/citation.cfm?id=127830
// 空间复杂度：O(n)
// 使用坏字符规则实现 BM
function indexOf(mainStr, pattern) {
    if (!mainStr || !pattern) return -1

    const m = mainStr.length, n = pattern.length
    if (m < n) return -1

    // 数据(模式串)预处理, 构建坏字符哈希表
    const bc = genBadCharIndexMap(pattern)

    // 数据预处理：构建好后缀规则
    const suffix = new Array(n).fill(-1)
    const prefix = new Array(n).fill(false)
    genGoodSuffixArr(pattern, suffix, prefix)

    let i = 0 // i 表示每次匹配的时候，主串的起始位置，初始化为 0
    while (i <= m - n) {
        // 1. 找到第一个坏字符
        let y
        for (y = n - 1; y >= 0 ; y--) { // 从后往前匹配
            if (mainStr[i + y] != pattern[y]) break
        }

        // 2. 表示匹配成功
        if (y < 0) {
            // 返回主串和模式串第一个匹配字符串的位置
            return i
        }

        // 3. 匹配不成功，模式串往后移动
        // 先计算坏字符在模式串中的位置 x
        const badChar = mainStr[i + y]
        const x = bc.has(badChar) ? bc.get(badChar) : -1
        const badCharMoveSteps = y - x

        // 根据好后缀规则，计算移动的位数
        let goodSuffixMoveSteps = 0
        if (y < n - 1) { // 说明有好后缀，否则没有
            goodSuffixMoveSteps = calMoveSteps(y, n, suffix, prefix)
        }

        // 4. 往后移动最大位数
        i = i + Math.max(badCharMoveSteps, goodSuffixMoveSteps)
    }

    return -1
}

const mainStr = "aaabaaa";
const patternStr = "baaa";

console.log(indexOf(mainStr, patternStr))