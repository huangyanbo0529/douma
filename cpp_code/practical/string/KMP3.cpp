/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getNext(string pattern) { // O(n^3)
    int n = pattern.length();
    // bug 修复： 如果只有一个字符的话，就不计算 next 数组
    if (n == 1) return {};

    vector<int> next(n - 1, 0);

    next[0] = -1;

    for (int j = 1; j < n - 1; j++) {
        int pre = next[j - 1];
        while (pre != -1 && pattern[pre + 1] != pattern[j]) {
            // 因为前一个最长串的下一个字符不与最后一个相等，所以需要找前一个的次长串
            // 问题就变成了求 0 到 next(pre) 的最长串
            pre = next[pre];
        }
        if (pattern[pre + 1] == pattern[j]) {
            pre++;
        }
        next[j] = pre;
    }
    // 最值问题
    return next;
}

// 最好情况下时间复杂度：O(m)
// 最坏情况下时间复杂度：O(mn)
// 空间复杂度：O(n)
int indexOf(string mainStr, string pattern) {
    int m = mainStr.length();
    int n = pattern.length();
    if (m < n) return -1;

    // 根据模式串所有的前缀，计算得到 next 数组
    vector<int> next = getNext(pattern);

    int j = 0;
    for (int i = 0; i < m; i++) {
        while (j > 0 && mainStr[i] != pattern[j]) {
            // 就不从头开始匹配了，直接跳到下一个最长匹配前缀字符串的结尾字符的下一个字符位置
            j = next[j - 1] + 1;
        }

        if (mainStr[i] == pattern[j]) {
            j++;
        }

        if (j == n) {
            return i - n + 1;
        }
    }

    return -1;
}

int main() {
    string mainStr = "aaabaaa";
    string patternStr = "baaa";

    cout << indexOf(mainStr, patternStr) << endl;
    return 0;
}