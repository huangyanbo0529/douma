/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <unordered_map>

using namespace std;

class LocalCache {
private:
    unordered_map<int, int> cache;

public:
    int get(int key) {
        return cache[key];
    }

    int put(int key, int value) {
        return cache[key] = value;
    }
};