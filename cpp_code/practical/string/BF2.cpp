/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>
#include <string>

using namespace std;

// 时间复杂度：O(mn)
// 空间复杂度：O(1)
int indexOf(string mainStr, string pattern) {
    int m = mainStr.length();
    int n = pattern.length();
    if (m < n) return -1;

    char first = pattern[0];
    for (int i = 0; i < m; i++) {
        // 1. 找到等于模式串中第一个字符的位置
        if (mainStr[i] != first) {
            while (++i < m && mainStr[i] != first);
        }

        if (i < m) {
            // 2. 比对后面的字符，如果相等的话，一直比对下去
            int k = i + 1;
            int j = 1;
            // bug 修复，如果 j 已经超出了 pattern 范围
            // 说明已经找到了，则直接返回
            if (j == n) return i;
            for (; j < n && k < m ; j++, k++) {
                if (mainStr[k] == pattern[j]) {
                    // 3. 如果 j 是模式串的最后一个字符，说明匹配到了模式串
                    if (j == n - 1) return i;
                } else { // 如果字符不相等，则退出循环
                    break;
                }
            }
        }
    }

    return -1;
}

int main() {
    string mainStr = "    your code";
    string patternStr = "your";

    cout << indexOf(mainStr, patternStr) << endl;
    return 0;
}