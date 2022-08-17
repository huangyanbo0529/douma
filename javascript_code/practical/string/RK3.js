// 抖码算法，让算法学习变的简单有趣
// 作者：老汤

function calHashCode(str, i, hashCodes, n) {
    return hashCodes[i - 1] * 26
        - (mainStr[i - 1].charCodeAt(0) - 'a'.charCodeAt(0)) * Math.pow(26, n)
        + (mainStr[i + n - 1].charCodeAt(0) - 'a'.charCodeAt(0))
}

// abc => 0 * 26^2 + 1 * 26 + 2 = 28
function calFirstSubStrHashCode(str) { // O(n)
    const n = str.length
    let hashCode = 0
    for (let i = 0; i < n; i++) {
        hashCode += (str[n - i - 1].charCodeAt(0) - 'a'.charCodeAt(0)) * Math.pow(26, i)
    }
    return hashCode
}

// 时间复杂度：O(m - n)
// 空间复杂度：O(m - n)
function indexOf(mainStr, pattern) {
    if (!mainStr || !pattern) return -1

    const m = mainStr.length, n = pattern.length
    if (m < n) return -1

    // 1. 计算主串中 m - n + 1 个子串的哈希值
    const hashCodes = new Array(m - n + 1);
    // 计算第一个子串的 hash 值
    hashCodes[0] = calFirstSubStrHashCode(mainStr.substring(0, n))
    for (let i = 1; i < m - n + 1; i++) {
        // 根据前一个子串的 hash 值计算下一个子串的 hash 值
        hashCodes[i] = calHashCode(mainStr, i, hashCodes, n);
    }

    // 2. 计算模式串的哈希值
    const hashCode = calFirstSubStrHashCode(pattern);

    // 3. 在所有子串哈希值中，寻找是否有模式串的哈希值
    for (let i = 0; i < m - n + 1; i++) {
        if (hashCode == hashCodes[i]) {
            return i
        }
    }

    return -1;
}

const mainStr = "    your code";
const patternStr = "your";

console.log(indexOf(mainStr, patternStr))