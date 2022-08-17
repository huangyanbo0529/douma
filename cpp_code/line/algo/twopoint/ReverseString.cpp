/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
using std::vector;

void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        char c = s[left];
        s[left] = s[right];
        s[right] = c;

        left++;
        right--;
    }
}