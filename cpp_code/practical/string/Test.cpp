/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <string>
#include <iostream>


using namespace std;

int main() {
    string mainStr = "douma, shake your code"; // 主串
    string patternStr = "your"; // 模式串

    int index = mainStr.find(patternStr);
    cout << index << endl;

    // BF、RK、BM、KMP
    return 0;
}