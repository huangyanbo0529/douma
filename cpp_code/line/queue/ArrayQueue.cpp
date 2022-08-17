/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <string>
#include <vector>
#include <iostream>
#include "Queue.h"

using namespace std;

template <typename E>

class ArrayQueue: public Queue<E>{
private:
    vector<E> data;

public:
    int getSize() {
        return data.size();
    }

    bool isEmpty() {
        return data.size() == 0;
    }

    void enqueue(E e) {
        data.push_back(e);
    }

    // 时间复杂度：O(n)
    E dequeue() {
        if (isEmpty()) {
            throw "队列空了，没有元素可以出队";
        }
        E res = data.front();
        // 删除 vector 的第一个元素
        // 将第一个元素后面的元素，都往前移动一位
        for (int i = 1; i < data.size(); ++i) {
            data[i - 1] = data[i];
        }
        // 删掉最后一个元素
        data.pop_back();
        return res;
    }

    E getFront() {
        if (isEmpty()) {
            throw "队列空了，没有元素可以被返回";
        }
        return data.front();
    }

    string toString() {
        string res = "Queue：队首 [";
        for (int i = 0; i < data.size(); ++i) {
            res += to_string(data[i]);
            if (i != data.size() - 1) {
                res += ", ";
            }
        }
        res += "]";
        return res;
    }
};

int main() {
    ArrayQueue<int> queue;
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