/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calHashCode(string str) {
    return hash <string> () (str); // O(n)
}

// 时间复杂度：O((m - n)*n)
// 空间复杂度：O(m - n)
int indexOf(string mainStr, string pattern) {
    int m = mainStr.length();
    int n = pattern.length();
    if (m < n) return -1;

    // 1. 计算主串中 m - n + 1 个子串的哈希值
    vector<int> hashCodes(m - n + 1);
    for (int i = 0; i < m - n + 1; i++) {
        hashCodes[i] = calHashCode(mainStr.substr(i, n));
    }

    // 2. 计算模式串的哈希值
    int hashCode = calHashCode(pattern);

    // 3. 在所有子串哈希值中，寻找是否有模式串的哈希值
    for (int i = 0; i < m - n + 1; i++) {
        if (hashCode == hashCodes[i]) {
            return i;
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