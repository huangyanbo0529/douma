/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <string>
#include <iostream>
#include <vector>

#include "Stack.h"
using namespace std;

template<typename E>
class DynamicArrayStack: public Stack<E>{
private:
    // 这里使用 C++ 中内置的动态数组 vector
    vector<E> data;

public:
    int getSize() {
        return data.size();
    }

    bool isEmpty() {
        return data.size() == 0;
    }

    // 时间复杂度：O(1)
    void push(E e) {
        data.push_back(e);
    }

    // 时间复杂度：O(1)
    E pop() {
        if (isEmpty()) {
            throw "pop failed, stack is empty";
        }
        E res = data.back();
        data.pop_back();
        return res;
    }

    // 时间复杂度：O(1)
    E peek() {
        if (isEmpty()) {
            throw "pop failed, stack is empty";
        }
        return data.back();
    }

     string toString() {
        string res = "";
        res += "Stack: [";
        for (int i = 0; i < data.size(); i++) {
            res += to_string(data[i]);
            if (i != data.size() - 1) {
                res += ",";
            }
        }
         res += "] top";
        return res;
    }
};

int main() {
    DynamicArrayStack<int> stack;

    stack.push(10);
    cout << stack.toString() << endl;

    stack.push(20);
    cout << stack.toString() << endl;

    stack.push(30);
    cout << stack.toString() << endl;

    stack.pop();
    cout << stack.toString() << endl;

    stack.pop();
    cout << stack.toString() << endl;

    return 0;
}