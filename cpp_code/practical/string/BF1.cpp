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

    for (int i = 0; i < m; i++) {
        // 1. 比对后面的字符，如果相等的话，一直比对下去
        int k = i;
        for (int j = 0; j < n; j++) {
            if (k < m && pattern[j] == mainStr[k]) {
                k++;

                // 2. 如果 j 是模式串的最后一个字符，说明匹配到了模式串
                if (j == n - 1) return i;
            } else {
                break;
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