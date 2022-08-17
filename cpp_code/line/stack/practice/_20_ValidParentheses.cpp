/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <string>
#include <stack>
using namespace std;

bool isValid1(std::string s) {
    if (s.size() % 2 == 1) return false;
    // 使用 C++ 内置的 stack
    stack<int> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char topChar = st.top();
            st.pop();
            if (c == ')' && topChar != '(') return false;
            if (c == ']' && topChar != '[') return false;
            if (c == '}' && topChar != '{') return false;
        }
    }
    return st.empty();
}