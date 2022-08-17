/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calHashCode(string mainStr, int i, vector<int> hashCodes, int n) {
    return hashCodes[i - 1] - (mainStr[i - 1] - 'a')
           + (mainStr[i + n - 1] - 'a');
}

// abc => 0 + 1 + 2 = 3
int calFirstSubStrHashCode(string str) { // O(n)
    int n = str.length();

    int hashCode = 0;
    for (int i = 0; i < n; i++) {
        hashCode += (str[n - i - 1] - 'a');
    }

    return hashCode;
}

// 时间复杂度：O((m - n)*n)
// 空间复杂度：O(m - n)
int indexOf(string mainStr, string pattern) {
    int m = mainStr.length();
    int n = pattern.length();
    if (m < n) return -1;

    // 1. 计算主串中 m - n + 1 个子串的哈希值
    vector<int> hashCodes(m - n + 1);
    // 计算第一个子串的 hash 值
    hashCodes[0] = calFirstSubStrHashCode(mainStr.substr(0, n));
    for (int i = 1; i < m - n + 1; i++) {
        // 根据前一个子串的 hash 值计算下一个子串的 hash 值
        hashCodes[i] = calHashCode(mainStr, i, hashCodes, n);
    }

    // 2. 计算模式串的哈希值
    int hashCode = calFirstSubStrHashCode(pattern);

    // 3. 在所有子串哈希值中，寻找是否有模式串的哈希值
    for (int i = 0; i < m - n + 1; i++) {
        // abc = 0 + 1 + 2 = 3
        // cba = 2 + 1 + 0 = 3
        if (hashCode == hashCodes[i]) {
            // 解决哈希冲突问题：将子串和模式串重新对比一遍
            int k = i;
            for (int j = 0; j < n && k < m; j++, k++) {
                if (mainStr[k] != pattern[j]) {
                    break;
                }
                if (j == n - 1) return i;
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