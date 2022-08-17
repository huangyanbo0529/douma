/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <iostream>

#define byte unsigned char

using namespace std;

class BitMap {
private:
    vector<byte> bytes;
    int nBits;

public:
    BitMap(int nBits): nBits(nBits) {
        this->bytes = vector<byte>(nBits / 8 + 1);
    }

    void set(int num) {
        if (num > nBits) return;
        // 找到第几个字节
        int byteIndex = num / 8;
        // 找到第几位
        int bitIndex = num % 8;
        bytes[byteIndex] |= (1 << bitIndex);
    }

    bool contains(int target) {
        if (target > nBits) return false;
        // 找到第几个字节
        int byteIndex = target / 8;
        // 找到第几位
        int bitIndex = target % 8;
        return ((1 << bitIndex) & bytes[byteIndex]) != 0;
    }
};

int main() {
    vector<int> data = {2, 7, 2, 5, 3};
    int target = 2;

    BitMap bitMap1(8);
    for (int i = 0; i < data.size(); i++) {
        bitMap1.set(data[i]);
    }


    if (bitMap1.contains(target)) {
        cout << "存在目标值：" << to_string(target) << endl;
    }
    return 0;
}