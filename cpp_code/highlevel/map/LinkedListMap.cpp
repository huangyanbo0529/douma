/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>

#include "Map.h"

using namespace std;

template<typename K, typename V>
struct Node {
    K key;
    V* value;
    Node<K, V>* next;

    Node(int key, V* value, Node* next): key(key), value(value), next(next) {}

    Node(int key, V* value): key(key), value(value), next(nullptr) {}

    Node(): key(), value(), next(nullptr) {}
};

template<typename K, typename V, typename Compare>
class LinkedListMap: public Map<K, V> {
private:
    Node<K, V>* dummyHead;
    int __size = 0;
    Compare __equal;

public:
    LinkedListMap(Compare __equal) : __equal(__equal) {
        dummyHead = new Node<K, V>();
    }

    int size() {
        return __size;
    }

    bool isEmpty() {
        return __size == 0;
    }

    void add(K key, V&& value) { // O(n)
        // 1. 找到 key 对应的 value 所在的节点
        Node<K, V>* curr = getNode(key);

        // 2. 如果 curr 为空的话，说明 Map 中还没有这个键值对
        if (curr == nullptr) {
            // 直接将键值对插入头节点即可
            dummyHead->next = new Node<K, V>(key, &value, dummyHead->next);
            __size++;
        } else {
            // 键值对已经存在，那么更新 value
            curr->value = &value;
        }
    }

    Node<K, V>* getNode(K key) { // O(n)
        Node<K, V>* curr = dummyHead->next;
        while (curr != nullptr) {
            if (__equal(key, curr->key)) {
                break;
            }
            curr = curr->next;
        }
        return curr;
    }

    V* remove(K key) { // O(n)
        // 1. 找到需要删除的节点的前一个节点
        Node<K, V>* prev = dummyHead;
        Node<K, V>* curr = dummyHead->next;
        while (curr != nullptr) {
            if (__equal(key, curr->key)) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        // 2. 如果需要删除的节点不为空，则删除节点，并返回删除节点的值
        if (curr != nullptr) {
            prev->next = curr->next;
            curr->next = nullptr;
            __size--;
            return curr->value;
        }
        return nullptr;
    }

    void set(K key, V&& newValue) { // O(n)
        // 1. 找到 key 对应的 value 所在的节点
        Node<K, V>* curr = getNode(key);

        if (curr != nullptr) curr->value = &newValue;
        else throw "没有对应的 key ：" + key;
    }

    V* get(K key) { // O(n)
        Node<K, V>* node = getNode(key);
        return node == nullptr ? nullptr : node->value;
    }

    bool containsKey(K key) { // O(n)
        Node<K, V>* node = getNode(key);
        // 如果 node 不为 null ，则表示存在，否则表述不存在
        return node != nullptr;
    }


};

int main() {
    LinkedListMap<int, int, decltype(&intEqual)> map(intEqual);
    map.add(10, 100);

    map.add(10, 344);

    int* res = map.get(10);

    cout << *res << endl;

    return 0;
}