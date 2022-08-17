/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include "Set.h"
#include <vector>
#include <math.h>
#include <sstream>
#include <iostream>
#include <functional>

#include <unordered_set>

#include "../../tree/bst/BST.cpp"

template <typename E>
struct Item {
    E data;
    bool isDeleted;

    Item(E data): data(data), isDeleted(false) {}
};


// 开放寻址方式解决哈希冲突
template <typename E, typename HASH, typename Compare>
class HashSet2 : public Set<E> {
private:
    vector<Item<E>*> items;
    int __size;
    int deleteCount; // 用于记录有多少标记删除的元素
    // 装载因子
    double loadFactor = 0.75;
    HASH __hash;
    Compare __equal;

    int hash(E &e, int length) {
        // 对象哈希值通过外面传进来
        return __hash(e) % length;
    }

public:
    HashSet2(int capacity, HASH __hash, Compare __equal): __hash(__hash), __equal(__equal) {
        this->items.resize(capacity);
        for (int i = 0; i < capacity; ++i) {
            this->items[i] = nullptr;
        }
        this->__size = 0;
        this->deleteCount = 0;
    }

    int size() {
        return __size;
    }

    bool isEmpty() {
        return __size == 0;
    }

    void add(E&& e) {
        int index = hash(e, items.size());
        // addIndex 表示元素 e 需要插入的索引位置
        int addIndex = index;
        // isFirst 用于辅助找到元素 e 插入的位置
        bool isFirst = true;

        // bug 修复：add 前先判断是否存在元素 e
        while (items[index] != nullptr && !__equal(e, items[index]->data)) {
            // 找到第一个等于 null 或者删除的元素，并记录赋值给 addIndex
            if ((items[index] == nullptr || items[index]->isDeleted) && isFirst) {
                addIndex = index;
                isFirst = false;
            }

            index++;
            index = index % items.size();
        }
        // 说明已经存在 e，则直接返回
        if (items[index] != nullptr && !items[index]->isDeleted) return;

        // 这个时候的 addIndex 对应的元素要么是 null ，要么是已经删除的元素
        // 如果 addIndex 对应的元素是标记为删除的元素，那么直接被覆盖了，标记为删除的元素个数减少 1
        if (items[addIndex] != nullptr && items[addIndex]->isDeleted) deleteCount--;
        items[addIndex] = new Item<E>(e);
        __size++;

        if (__size >= items.size() * loadFactor) {
            resize(2 * items.size());
        }
    }

    void resize(int newCapacity) {
        vector<Item<E>*> newData(newCapacity);
        for (int i = 0; i < items.size(); i++) {
            if (items[i] != nullptr && !items[i]->isDeleted) {
                int newIndex = hash(items[i]->data, newCapacity);
                newData[newIndex] = items[i];
            }
        }
        // 所有标记为删除的元素都清理掉了
        deleteCount = 0;
        items = newData;
    }

    void remove(E&& e) {
        int index = hash(e, items.size());
        // 找到等于 e 或者元素为 null 的索引
        while (items[index] != nullptr && !__equal(e, items[index]->data)) {
            index++;
            index = index % items.size();
        }
        if (items[index] != nullptr) {
            items[index]->isDeleted = true;
            __size--;
            deleteCount++;
        }
        // 如果标记为删除的元素太多的话，我们进行 resize，清除标记为删除的元素
        // TODO：这里可能会产生时间复杂度震荡
        if (deleteCount + __size >= items.size() * loadFactor) {
            resize(items.size());
        }
    }

    bool contains(E&& e) {
        int index = hash(e, items.size());

        // 找到等于 e 或者元素为 null 的索引
        while (items[index] != nullptr && !__equal(e, items[index]->data)) {
            index++;
            index = index % items.size();
        }

        return items[index] != nullptr && !items[index]->isDeleted;
    }

    string toString() {
        stringstream fmt;
        for (int i = 0; i < items.size(); ++i) {
            if (items[i] != nullptr && !items[i]->isDeleted) {
                fmt << to_string(items[i]->data) << ", ";
            }
        }
        return fmt.str();
    }
};

int main() {
    HashSet2<int, decltype(&intHash), decltype(&intEqual)> set(30, intHash, intEqual);
    set.add(2);
    set.add(4);
    set.add(1);

    cout << set.toString() << endl;

    set.add(2);
    cout << set.toString() << endl;

    cout << to_string(set.contains(4)) << endl;

    set.remove(1);
    cout << set.toString() << endl;

    return 0;
}