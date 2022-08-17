/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include "Set.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

#include "../../tree/bst/BST.cpp"

using namespace std;

template<typename E>
class BSTSet : public Set<E> {
private:
    BST<E> data;

public:
    int size() {
        return data.getSize();
    }

    bool isEmpty() {
        return data.isEmpty();
    }

    void add(E e) { // O(n)
        data.add(e);
    }

    void remove(E e) { // O(n)
        data.remove(e);
    }

    bool contains(E e) { // O(n)
        return data.contains(e);
    }

    string toString() {
        vector<E> res = data.inOrder();
        stringstream fmt;
        for (int i = 0; i < res.size(); ++i) {
            fmt << to_string(res[i]) << ", ";
        }
        return fmt.str();
    }
};

int main() {
    Set<int>* set = new BSTSet<int>();
    set->add(2);
    set->add(4);
    set->add(1);

    cout << set->toString() << endl;

    set->add(2);
    cout << set->toString() << endl;

    cout << to_string(set->contains(4)) << endl;

    set->remove(1);
    cout << set->toString() << endl;

    return 0;
}