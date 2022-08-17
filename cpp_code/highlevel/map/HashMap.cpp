/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <math.h>
#include <vector>
#include <iostream>

#include "Map.h"

using namespace std;

template <typename K, typename V>
struct Node {
    K key;
    V* value;
    Node* next;

    Node(int key, V* value, Node* next): key(key), value(value), next(next) {}

    Node(int key, V* value): key(key), value(value), next(nullptr) {}

    Node(): key(), value(), next(nullptr) {}
};

template <typename K, typename V, typename HASH, typename Compare>
class HashMap: public Map<K, V> {
private:
    vector<Node<K, V>*> data;
    int __size;
    double loadFactor;
    int capacity;
    HASH __hash;
    Compare __equal;

    int hash(K key, int length) {
        // 对象哈希值通过外面传进来
        return __hash(key) % length;
    }

    Node<K, V>* getNode(K key, int index) {
        Node<K, V>* curr = data[index];
        while (curr != nullptr) {
            if (__equal(curr->key, key)) {
                break;
            }
            curr = curr->next;
        }
        return curr;
    }

    void resize(int newCapacity) {
        vector<Node<K, V>*> newData(newCapacity, nullptr);
        for (int i = 0; i < capacity; i++) {
            Node<K, V>* curr = data[i];
            while (curr != nullptr) {
                int key = curr->key;
                int newIndex = hash(key, newCapacity);
                Node<K, V>* head = newData[newIndex];
                newData[newIndex] = new Node<K, V>(key, curr->value);
                if (head != nullptr) {
                    newData[newIndex]->next = head;
                }
                curr = curr->next;
            }
        }
        data = newData;
    }

public:
    HashMap(int initCapacity, double loadFactor, HASH __hash, Compare __equal): __hash(__hash), __equal(__equal) {
        this->data.resize(initCapacity);
        for (int i = 0; i < initCapacity; ++i) {
            data[i] = nullptr;
        }
        this->__size = 0;
        this->loadFactor = loadFactor;
        this->capacity = initCapacity;
    }

    int size() {
        return __size;
    }

    bool isEmpty() {
        return __size == 0;
    }

    void add(K key, V&& value) {
        int index = hash(key, capacity);
        Node<K, V>* curr = getNode(key, index);
        if (curr == nullptr) {
            data[index] = new Node<K, V>(key, &value, data[index]);
            __size++;
            if (__size >= capacity * loadFactor) {
                resize(2 * capacity);
            }
        } else {
            curr->value = &value;
        }
    }

    V* remove(K key) {
        int index = hash(key, capacity);
        if (data[index] == nullptr) {
            return nullptr;
        }
        Node<K, V>* prev = nullptr;
        Node<K, V>* curr = data[index];
        while (curr != nullptr) {
            if (__equal(curr->key, key)) {
                if (prev == nullptr) {
                    // 删除头节点
                    data[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                curr->next = nullptr;
                __size--;
                return curr->value;
            }
            prev = curr;
            curr = curr->next;
        }
        return nullptr;
    }

    void set(K key, V&& newValue) {
        int index = hash(key, capacity);
        Node<K, V>* node = getNode(key, index);
        if (node == nullptr) {
            throw "没有对应的 key ：" + key;
        }
        node->value = &newValue;
    }

    V* get(K key) {
        int index = hash(key, capacity);
        Node<K, V>* node = getNode(key, index);
        return node == nullptr ? nullptr : node->value;
    }

    bool containsKey(K key) {
        int index = hash(key, capacity);
        Node<K, V>* node = getNode(key, index);
        return node != nullptr;
    }

};

int main() {
    HashMap<int, int, decltype(&intHash), decltype(&intEqual)> map(10, 0.75, intHash, intEqual);
    map.add(10,100);
    map.add(10, 3444);

    int* res = map.get(10);

    cout << *res << endl;

    return 0;
}