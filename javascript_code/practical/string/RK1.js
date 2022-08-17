// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


// 因为 js 没有内置的 hashCode 方法
// 所以，我们自己实现一个
// 时间复杂度：O(n)
function calHashCode(str) {
    let hash = 0
    if (str.length == 0) return hash
    for (let i = 0; i < str.length; i++) {
        const char = str.charCodeAt(i)
        hash = ((hash << 5) - hash) + char
        hash = hash & hash; // Convert to 32bit integer
    }
    return hash;
}

// 时间复杂度：O((m - n)*n)
// 空间复杂度：O(m - n)
function indexOf(mainStr, pattern) {
    if (!mainStr || !pattern) return -1

    const m = mainStr.length, n = pattern.length
    if (m < n) return -1

    // 1. 计算主串中 m - n + 1 个子串的哈希值
    const hashCodes = new Array(m - n + 1);
    for (let i = 0; i < m - n + 1; i++) {
        hashCodes[i] = calHashCode(mainStr.substring(i, i + n));
    }

    // 2. 计算模式串的哈希值
    const hashCode = calHashCode(pattern);

    // 3. 在所有子串哈希值中，寻找是否有模式串的哈希值
    for (let i = 0; i < m - n + 1; i++) {
        if (hashCode == hashCodes[i]) {
            return i;
        }
    }

    return -1;
}

const mainStr = "    your code";
const patternStr = "your";

console.log(indexOf(mainStr, patternStr))