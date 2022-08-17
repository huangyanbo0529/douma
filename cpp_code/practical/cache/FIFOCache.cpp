/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <unordered_map>
#include <queue>

using namespace std;

class FIFOCache {
private:
    unordered_map<int, int> cache;
    queue<int> q;
    int capacity;

public:

    FIFOCache(int capacity): capacity(capacity) {}

    int get(int key) {
        return cache[key];
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            if (cache.size() == capacity) {
                int oldKey = q.front();
                q.pop();
                cache.erase(oldKey);
            }
            q.push(key);
        }
        cache[key] = value;
    }
};