/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <string>
#include <vector>
#include <iostream>
#include "Queue.h"

using namespace std;


template<typename E>
struct Node {
    E e;
    Node* next;

    Node(){}

    Node(E e) : e(e), next(nullptr) {}

    Node(E e, Node<E>* next) : e(e), next(next) {}

    string toString() {
        return to_string(e);
    }
};


template <typename E>

class LinkedListQueue2: public Queue<E>{
private:
    Node<E>* head;
    Node<E>* tail;
    int size;

public:
    LinkedListQueue2() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(E e) {
        Node<E>* newNode = new Node<E>(e);
        if (tail == nullptr) {
            tail = newNode;
            head = tail;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // 时间复杂度：O(n)
    E dequeue() {
        if (isEmpty()) {
            throw "队列空了，没有元素可以出队";
        }
        Node<E>* delNode = head;
        head = head->next;
        delNode->next = nullptr;

        if (head == nullptr) {
            tail = nullptr;
        }

        size--;
        return delNode->e;
    }

    E getFront() {
        if (isEmpty()) {
            throw "队列空了，没有元素可以被返回";
        }
        return head->e;
    }

    string toString() {
        string res = "Queue：队首 [";
        Node<E>* curr = head;
        while (curr != nullptr) {
            res += curr->toString() + "=>";
            curr = curr->next;
        }
        res += "null]";
        return res;
    }
};

int main() {
    LinkedListQueue2<int> queue;
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