/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include "Set.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <functional>

template <typename E>
struct Node {
    E e;
    Node<E>* next;

    Node(int e): e(e), next(nullptr) {}
};


// 链表法解决哈希冲突
template <typename E, typename HASH, typename Compare>
class HashSet3 : public Set<E> {
private:
    vector<Node<E>*> data;
    int __size;
    // 装载因子
    double loadFactor = 0.75;
    HASH __hash;
    Compare __equal;

    int hash(E &e, int length) {
        // 对象哈希值通过外面传进来
        return __hash(e) % length;
    }

public:
    HashSet3(int capacity, HASH __hash, Compare __equal): __hash(__hash), __equal(__equal) {
        this->data.resize(capacity);
        for (int i = 0; i < capacity; ++i) {
            this->data[i] = nullptr;
        }
        this->__size = 0;
    }

    int size() {
        return __size;
    }

    bool isEmpty() {
        return __size == 0;
    }

    void add(E&& e) {
        int index = hash(e, data.size());
        if (data[index] == nullptr) {
            data[index] = new Node<E>(e);
        } else {
            Node<E>* prev = nullptr;
            Node<E>* curr = data[index];
            while (curr != nullptr) {
                if (__equal(e, curr->e)) {
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
            prev->next = new Node<E>(e);
        }
        __size++;
        if (__size >= data.size() * loadFactor) {
            resize(2 * data.size());
        }
    }

    void resize(int newCapacity) {
        vector<Node<E>*> newData(newCapacity);
        for (int i = 0; i < data.size(); i++) {
            Node<E>* curr = data[i];
            while (curr != nullptr) {
                int e = curr->e;
                int newIndex = hash(e, newCapacity);
                Node<E>* head = newData[newIndex];
                newData[newIndex] = new Node<E>(e);
                if (head != nullptr) {
                    newData[newIndex]->next = head;
                }
                // bug 修复：curr 需要往前移动
                curr = curr->next;
            }
        }
        data = newData;
    }

    void remove(E&& e) {
        int index = hash(e, data.size());
        if (data[index] == nullptr) {
            return;
        }
        Node<E>* prev = nullptr;
        Node<E>* curr = data[index];
        while (curr != nullptr) {
            if (__equal(e, curr->e)) {
                if (prev == nullptr) {
                    // 删除头节点
                    data[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                curr->next = nullptr;
                __size--;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    bool contains(E&& e) { // O(n)
        int index = hash(e, data.size());
        if (data[index] == nullptr) return false;
        Node<E>* curr = data[index];
        while (curr != nullptr) {
            if (__equal(e, curr->e)) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    string toString() {
        stringstream fmt;
        for (int i = 0; i < data.size(); ++i) {
            Node<E>* curr = data[i];
            while (curr != nullptr) {
                fmt << to_string(curr->e) << ", ";
                curr = curr->next;
            }
            if (data[i] != nullptr) fmt << "\n";
        }
        return fmt.str();
    }
};

int main() {
    HashSet3<int, decltype(&intHash), decltype(&intEqual)> set(30, intHash, intEqual);
    set.add(2);
    set.add(4);
    set.add(1);

    cout << set.toString() << endl;
    cout << "................................." << endl;

    set.add(2);
    cout << set.toString() << endl;
    cout << "................................." << endl;

    cout << to_string(set.contains(4)) << endl;
    cout << "................................." << endl;

    set.remove(1);
    cout << set.toString() << endl;
    cout << "................................." << endl;

    return 0;
}