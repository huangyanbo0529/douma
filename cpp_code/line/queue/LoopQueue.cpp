/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Queue.h"

using namespace std;

template <typename E>

class LoopQueue: public Queue<E> {
private:
    E* data;
    int capacity;
    int size;
    int head;
    int tail;

    void resize(int newCapacity) {
        E* newData = new E[newCapacity + 1];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[(i + head) % capacity];
        }
        data = newData;
        head = 0;
        tail = size;
        capacity = newCapacity + 1;
    }

public:

    LoopQueue(int capacity) {
        this->capacity = capacity;
        this->data = new E[capacity];
        this->size = 0;
        this->head = 0;
        this->tail = 0;
    }

    int getCapacity() {
        return capacity - 1;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        // 这里也可以使用 size 来判断队列是否空的，参考 issue ：https://gitee.com/douma_edu/douma-algo/issues/I4WGCE
        return head == tail;
    }

    void enqueue(E e) {
        // 这里也可以使用 size 来判断队列是否满了，参考 issue ：https://gitee.com/douma_edu/douma-algo/issues/I4WGCE
        if ((tail + 1) % capacity == head) {
            // 队列满了
            resize(getCapacity() * 2);
        }
        data[tail] = e;
        size++;
        tail = (tail + 1) % capacity;
    }

    // 时间复杂度：O(n)
    E dequeue() {
        if (isEmpty()) {
            throw "队列空了，没有元素可以出队";
        }
        E res = data[head];
        size--;
        head = (head + 1) % capacity;
        if (size == getCapacity() / 4) {
            resize(getCapacity() / 2);
        }
        return res;
    }

    E getFront() {
        if (isEmpty()) {
            throw "队列空了，没有元素可以被返回";
        }
        return data[head];
    }

    string toString() {
        stringstream fmt;
        fmt << "Queue: size = " << size << ", capacity = " << getCapacity() << "\n";
        fmt << "Queue：队首 [";
        for (int i = head; i != tail; i = (i + 1) % capacity) {
            fmt << to_string(data[i]);
            if ((i + 1) % capacity != tail) {
                fmt << ", ";
            }
        }
        fmt << "]";
        return fmt.str();
    }
};

int main() {
    LoopQueue<int> queue(10);
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