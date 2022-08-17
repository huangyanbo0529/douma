/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include "Set.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

template<typename E>
class ArraySet : public Set<E> {
private:
    vector<E> data;

public:
    int size() {
        return data.size();
    }

    bool isEmpty() {
        return data.empty();
    }

    void add(E e) { // O(n)
        if (contains(e)) return;
        data.push_back(e);
    }

    void remove(E e) { // O(n)
        for (vector<int>::iterator iter = data.begin(); iter != data.end();) {
            if (*iter == e)
                iter = data.erase(iter);
            else
                iter++;
        }
    }

    bool contains(E e) { // O(n)
        for (int i = 0; i < data.size(); ++i) {
            // TODO：这里有 bug，不是所有类型的数据都有 == 这个操作的
            // 实际上除了 int 等基本类型外，其他类型都不支持 ==
            if (data[i] == e) return true;
        }
        return false;
    }

    string toString() {
        stringstream fmt;
        for (int i = 0; i < data.size(); ++i) {
            fmt << to_string(data[i]) << ", ";
        }
        return fmt.str();
    }
};

int main() {
    Set<int>* set = new ArraySet<int>();
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