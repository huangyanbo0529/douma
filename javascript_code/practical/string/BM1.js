// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


function genBadCharIndexMap(pattern) {
    const bc = new Map()
    for (let i = 0; i < pattern.length; i++) {
        bc.set(pattern[i], i)
    }
    return bc
}

// 时间复杂度：<= O((m - n)*n)
// 最好情况下时间复杂度：O(m/n)
// 空间复杂度：O(n)
// 使用坏字符规则实现 BM
function indexOf(mainStr, pattern) {
    if (!mainStr || !pattern) return -1

    const m = mainStr.length, n = pattern.length
    if (m < n) return -1

    // 数据(模式串)预处理, 构建坏字符哈希表
    const bc = genBadCharIndexMap(pattern)

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

        // 4. 往后移动 y - x 位
        // bug 修复：坏字符在模式串的中位置可能会大于 y，即 x 有可能大于 y
        // 比如：主串为 aaabaaabaaabaaaa 模式串为 aba
        // 解决方案就是：如果 y < x 的话，那么去选择往前走 1 步
        i = i + Math.max(1, y - x)
    }

    return -1
}

const mainStr = "    your code";
const patternStr = "your";

console.log(indexOf(mainStr, patternStr))