/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <string>
#include <iostream>

#include "../linkedlist/LinkedList.cpp"
#include "Stack.h"
using namespace std;

template<typename E>
class LinkedListStack: Stack<E> {
private:
    // 这里使用 C++ 中内置的动态数组 vector
    LinkedList<E>* data;

public:

    LinkedListStack() {
        this->data = new LinkedList<E>();
    }

    int getSize() {
        return data->getSize();
    }

    bool isEmpty() {
        return data->isEmpty();
    }

    // 时间复杂度：O(1)
    void push(E e) {
        data->addFirst(e);
    }

    // 时间复杂度：O(1)
    E pop() {
        if (isEmpty()) {
            throw "pop failed, stack is empty";
        }
        return data->removeFirst();
    }

    // 时间复杂度：O(1)
    E peek() {
        if (isEmpty()) {
            throw "pop failed, stack is empty";
        }
        return data->getFirst();
    }

     string toString() {
        string res = "";
        res += "Stack: [";
        for (int i = data->getSize() - 1; i >= 0; i--) {
            res += std::to_string(data->get(i));
            if (i != 0) {
                res += ",";
            }
        }
         res += "] top";
        return res;
    }
};

int main() {
    LinkedListStack<int> stack;

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