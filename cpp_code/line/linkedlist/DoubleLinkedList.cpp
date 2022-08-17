/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <string>
#include <iostream>

using namespace std;

template<typename E>
struct Node {
    E e;
    Node* next;
    Node* prev;

    Node(){}

    Node(E e) : e(e), next(nullptr) {}

    Node(Node<E>* prev, E e, Node<E>* next) : prev(prev), e(e), next(next) {}

    string toString() {
        return to_string(e);
    }
};

template<typename E>
class DoubleLinkedList {
private:
    Node<E>* first; // 头节点
    Node<E>* last; // 尾节点
    int size;

public:
    DoubleLinkedList() {
        this->first = nullptr;
        this->last = nullptr;
        this->size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    /**
     * 找到指定索引 index 所在的节点的元素值
     * @param index
     * @return
     */
    // 时间复杂度是 O(n)
    E get(int index) {
        Node<E>* node = node(index);
        if (node == nullptr) {
            throw "index failed, index must >= 0 and < size";
        }
        return node->e;
    }

    Node<E>* getFirst() {
        return first;
    }

    Node<E>* getLast() {
        return last;
    }

    // 时间复杂度是 O(n)
    Node<E>* node(int index) {
        if (index < 0 || index >= size)
            return nullptr;

        Node<E>* curr = nullptr;
        // 如果 index 小于链表长度的一半，则从 first 开始遍历查找
        if (index < size / 2) {
            curr = first;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
        } else { // 如果 index 大于等于链表长度的一半，则从 last 开始遍历查找
            curr = last;
            for (int i = 0; i < size - index - 1; i++) {
                curr = curr->prev;
            }
        }
        return curr;
    }

    // 时间复杂度是 O(n)
    void set(int index, E e) {
        // 先找到需要修改的节点
        Node<E>* node = node(index);
        if (node == nullptr) {
            throw "index failed, index must >= 0 and < size";
        }
        node->e = e;
    }

    /**
     * 往链表的表头插入节点
     * @param e
     */
    void addFirst(E e) {
        Node<E>* newNode = new Node<E>(e);
        if (first == nullptr) {
            // 如果头节点为空，说明链表中没有一个节点
            // 那么新插入的节点既是头节点，又是尾节点
            last = newNode;
        } else {
            // 将新节点作为头节点
            newNode->next = first;
            first->prev = newNode;
        }
        first = newNode;
        size++;
    }

    /**
     * 往链表尾巴插入新节点
     * @param e
     */
    void addLast(E e) {
        Node<E>* newNode = new Node<E>(e);
        if (last == nullptr) {
            // 如果尾节点为空，说明链表中没有一个节点
            // 那么新插入的节点既是头节点，又是尾节点
            first = newNode;
        } else {
            // 将新节点作为尾节点
            newNode->prev = last;
            last->next = newNode;
        }
        last = newNode;
        size++;
    }

    /**
     * 往指定索引位置插入节点
     * @param index
     * @param e
     */
    // 时间复杂度是 O(n)
    void add(int index, E e) {
        if (index < 0 || index > size)
            throw "add failed, index must >= 0 and <= size";

        if (index == size) {
            addLast(e);
        } else if (index == 0) {
            addFirst(e);
        } else {
            // 1. 找到要插入的位置，并记住这个位置的节点
            Node<E>* oldNode = node(index);
            Node<E>* prev = oldNode->prev;

            // 2. 新建节点，将它的 next 指向 oldNode，将它的 prev 指向 oldNode.prev
            Node<E>* newNode = new Node<E>(prev, e, oldNode);

            // 3. 将新建节点设置为 oldNode 的 prev
            oldNode->prev = newNode;

            // 4. 将新建节点设置 oldNode 之前的 prev 的 next
            prev->next = newNode;

            size++;
        }
    }

    E removeFirst() {
        if (first == nullptr) {
            throw "链表空的，所以没有元素可以删除";
        }
        E e = first->e;
        // 拿到头节点的下一个节点
        Node<E>* next = first->next;
        // 如果 next 为空，说明整个链表只有一个节点
        if (next == nullptr) {
            first = nullptr;
            last = nullptr;
        } else {
            // 将头节点从链表中断开
            first->next = nullptr;
            next->prev = nullptr;
            // 将 next 设置为头节点
            first = next;
        }
        size--;
        return e;
    }

    E removeLast() {
        if (last == nullptr) {
            throw "链表空的，所以没有元素可以删除";
        }
        E e = last->e;
        // 拿到尾节点的前一个节点
        Node<E>* prev = last->prev;
        // 如果 prev 为空，说明整个链表只有一个节点
        if (prev == nullptr) {
            last = nullptr;
            first = nullptr;
        } else {
            // 将尾节点从链表中断开
            last->prev = nullptr;
            prev->next = nullptr;
            // 将 prev 设置为尾节点
            last = prev;
        }
        size--;
        return e;
    }

    // 时间复杂度是 O(n)
    E remove(int index) {
        if (index < 0 || index >= size)
            throw "remove failed, index must >= 0 and < size";

        if (index == 0) {
            return removeFirst();
        } else if (index == size - 1) {
            return removeLast();
        }

        // 1. 找到要删除的节点
        Node<E>* delNode = node(index);
        E e = delNode->e;

        // 2. 记住要删除节点的 prev 和 next 节点
        Node<E>* prev = delNode->prev;
        Node<E>* next = delNode->next;

        // 3. 将删除节点的前后节点联系起来
        prev->next = next;
        next->prev = prev;

        // 4. 将删除节点从链表中断开
        delNode->next = nullptr;
        delNode->prev = nullptr;

        size--;
        return e;
    }

    string toString() {
        string res = "";
        Node<E>* curr = first;
        while (curr != nullptr) {
            res += curr->toString() + "=>";
            curr = curr->next;
        }
        res += "null";
        return res;
    }
};

int main() {
    DoubleLinkedList<int>* ll = new DoubleLinkedList<int>();
    ll->addLast(5);
    cout << ll->toString() << endl;

    ll->addFirst(10);
    cout << ll->toString() << endl;

    ll->add(2, 34);
    cout << ll->toString() << endl;

    ll->addFirst(50);
    cout << ll->toString() << endl;

    ll->remove(2);
    cout << ll->toString() << endl;

    ll->removeFirst();
    cout << ll->toString() << endl;
    return 0;
}