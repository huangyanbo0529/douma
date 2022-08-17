

const isValid = function (s) {
    if (s == null) return true

    // 代码优化：如果字符串的长度为奇数的话，那么肯定不是合法的
    if (s.length % 2 == 1) return false
    // 使用数组来代替栈
    const stack = []
    for (const c of s) {
        if (c == ' ') continue
        if (c == '(' || c == '{' || c == '[') {
            // 如果是左括号，则直接入栈
            stack.push(c)
        } else {
            if (stack.length == 0) {
                return false
            }
            // 判断栈顶元素是否等于左括号对应的右括号
            const topElement = stack.pop()
            let matched = '#'
            if (c == ')') {
                matched = '('
            } else if (c == ']') {
                matched = '['
            } else if (c == '}') {
                matched = '{'
            }
            if (matched != topElement) {
                return false
            }
        }
    }
    // 如果栈不为空，那么也算没有匹配好
    return stack.length == 0
}