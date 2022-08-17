/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <string>
#include <vector>
#include <iostream>

#include "../linkedlist/LinkedList.cpp"

#include "Queue.h"

using namespace std;


template <typename E>

class LinkedListQueue: public Queue<E>{
private:
    LinkedList<E> data;

public:
    int getSize() {
        return data.getSize();
    }

    bool isEmpty() {
        return data.getSize() == 0;
    }

    void enqueue(E e) {
        data.addLast(e);
    }

    // 时间复杂度：O(n)
    E dequeue() {
        if (isEmpty()) {
            throw "队列空了，没有元素可以出队";
        }
        return data.removeFirst();
    }

    E getFront() {
        if (isEmpty()) {
            throw "队列空了，没有元素可以被返回";
        }
        return data.getFirst();
    }

    string toString() {
        string res = "Queue：队首 [";
        for (int i = 0; i < data.getSize(); ++i) {
            res += to_string(data.get(i));
            if (i != data.getSize() - 1) {
                res += ", ";
            }
        }
        res += "]";
        return res;
    }
};

int main() {
    LinkedListQueue<int> queue;
    queue.enqueue(10);
    cout << queue.toString() << endl;

    queue.enqueue(20);
    cout << queue.toString() << endl;

    queue.enqueue(30);
    cout << queue.toString() << endl;

    queue.dequeue();
    cout << queue.toString() << endl;

    queue.dequeue();
    cout << queue.toString() << endl;
    return 0;
}