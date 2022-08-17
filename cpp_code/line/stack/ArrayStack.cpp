/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <string>
#include <iostream>
#include "Stack.h"

using namespace std;

template<typename E>
class ArrayStack: public Stack<E>{
private:
    E* data;
    int capacity;
    int size;

public:
    ArrayStack(int capacity) {
        this->capacity = capacity;
        this->data = new E[capacity];
        this->size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(E e) {
            if (size == capacity) {
                throw "push failed, Stack is full";
            }
            data[size] = e;
            size++;
        }

    E pop() {
        if (isEmpty()) {
            throw "pop failed, stack is empty";
        }
        E ret = data[size - 1];
        size--;
        return ret;
    }

    E peek() {
        if (isEmpty()) {
            throw "peek failed, stack is empty";
        }
        return data[size - 1];
    }

     string toString() {
        string res = "";
        res += "Stack: [";
        for (int i = 0; i < size; i++) {
            res += to_string(data[i]);
            if (i != size - 1) {
                res += ",";
            }
        }
         res += "] top";
        return res;
    }
};

int main() {
    ArrayStack<int> stack(10);

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