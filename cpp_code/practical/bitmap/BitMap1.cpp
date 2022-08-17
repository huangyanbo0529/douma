/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <string>
#include <iostream>
#include <bitset>

#define byte unsigned char

using namespace std;

class BitMap1 {
private:
    byte b;

public:
    BitMap1(): b(0) {}

    void set(int num) {
        /*
            set 2
            00000001 << 2
            00000100
          | 00000000
          = 00000100

            set 2
            00000001 << 2
            00000100
          | 00000100
          = 00000100
         */
        b |= (1 << num);
    }

    bool contains(int target) {
        /*
            contains 4
            00000001 << 4
            00010000
          & 10101100
          = 00000000
         */
        // 10101100
        return ((1 << target) & b) != 0;
    }

    string toString() {
        bitset<32> t(b);
        return "BitMap{ b=" + t.to_string().substr(24) + "}";
    }
};

int main() {
    vector<int> data = {2, 7, 2, 5, 3};
    int target = 2;

    BitMap1 bitMap1;
    for (int i = 0; i < data.size(); i++) {
        bitMap1.set(data[i]);
    }

    cout << bitMap1.toString() << endl;

    if (bitMap1.contains(target)) {
        cout << "存在目标值：" << to_string(target) << endl;
    }
    return 0;
}