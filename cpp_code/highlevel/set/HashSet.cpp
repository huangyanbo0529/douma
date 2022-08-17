/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include "Set.h"
#include <vector>
#include <sstream>
#include <iostream>

template<typename E, typename HASH>
class HashSet : public Set<E> {
private:
    vector<E*> data;
    int capacity;
    int __size;
    HASH __hash;

    int hash(E &e, int length) {
        // 对象哈希值通过外面传进来
        return __hash(e) % length;
    }

public:
    HashSet(int capacity, HASH __hash): capacity(capacity), __hash(__hash) {
        data.resize(capacity);
        fill(data.begin(),  data.end(), nullptr);
        __size = 0;
    }

    int size() {
        return __size;
    }

    bool isEmpty() {
        return __size == 0;
    }

    void add(E&& e) { // O(n)
        int index = hash(e, capacity);
        if (data[index] == nullptr) {
            data[index] = &e;
            __size++;

            if (__size == capacity) {
                resize(2 * capacity);
            }
        }
    }

    void resize(int newCapacity) {
        vector<E*> newData(newCapacity);
        for (int i = 0; i < capacity; i++) {
            if (data[i] != nullptr) {
                int newIndex = hash(*data[i], newCapacity);
                newData[newIndex] = data[i];
            }
        }
        data = newData;
        capacity = newCapacity;
    }

    void remove(E&& e) { // O(n)
        int index = hash(e, capacity);
        // bug 修复：在删除某个元素之前，先判断这个元素是否存在
        // 存在的话才删除
        if (data[index] != nullptr) {
            data[index] = nullptr;
            __size--;
        }
    }

    bool contains(E&& e) { // O(n)
        int index = hash(e, capacity);
        return data[index] != nullptr;
    }

    string toString() {
        stringstream fmt;
        for (int i = 0; i < capacity; ++i) {
            if (data[i] != nullptr) {
                fmt << to_string(*data[i]) << ", ";
            }
        }
        string res = fmt.str();
        return res;
    }
};

int main() {
    HashSet<int, decltype(&intHash)> set(10, intHash);
    set.add(2);
    set.add(3);
    set.add(3);
    set.add(5);

    cout << "set.toString()" << endl;
    cout << set.toString() << endl;

    set.remove(3);
    cout << set.toString() << endl;

    cout << set.contains(5) << endl;

    return 0;
}