def isValid(s):
    if s is None:
        return True
    # 代码优化：如果字符串的长度为奇数的话，那么肯定不是合法的
    if len(s) % 2 == 1:
        return False
    # Python 中使用数组可以实现栈的功能
    stack = []
    for c in s:
        if c == ' ':
            continue
        if c == '(' or c == '{' or c == '[':
            # 如果是左括号，则直接入栈
            stack.append(c)
        else:
            if not len(stack):
                return False
            # 判断栈顶元素是否等于左括号对应的右括号
            top_element = stack.pop()
            matched = '#'
            if c == ')':
                matched = '('
            elif c == ']':
                matched = '['
            else:
                matched = '{'
            if matched != top_element:
                return False
    # 如果栈不为空，那么也算没有匹配好
    return len(stack) == 0