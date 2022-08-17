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

    Node(): e(), next(nullptr){}

    Node(E e) : e(e), next(nullptr) {}

    Node(E e, Node<E>* next) : e(e), next(next) {}

    string toString() {
        return to_string(e);
    }
};

template<typename E>
class LinkedList {
private:
    // 虚拟头节点
    Node<E>* dummyHead;
    int size;

public:
    LinkedList() {
        this->dummyHead = new Node<E>();
        this->size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    /**
     * 查询指定索引的节点的值
     * @param index
     * @return
     */
    // 时间复杂度： O(n)
    E get(int index) {
        // 检查 index 的合法性
        if (index < 0 || index >= size)
            throw "get failed, index must >= 0 and < size";

        Node<E>* curr = dummyHead->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->e;
    }

    // 时间复杂度： O(1)
    E getFirst() {
        return get(0);
    }

    // 时间复杂度： O(n)
    E getLast() {
        return get(size - 1);
    }

    /**
     * 修改指定索引的节点元素
     * @param index
     * @param e
     */
    // 时间复杂度： O(n)
    void set(int index, E e) {
        // 检查 index 的合法性
        if (index < 0 || index >= size)
            throw "get failed, index must >= 0 and < size";

        Node<E>* curr = dummyHead->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        curr->e = e;
    }

    /**
     * 在链表表头新增节点
     * @param e 新增节点需要存储的数据
     */
    // 时间复杂度： O(1)
    void addFirst(E e) {
        add(0, e);
    }

    // 时间复杂度： O(n)
    void addLast(E e) {
        add(size, e);
    }

    /**
     * 在指定索引的位置插入新的节点
     * @param index 需要插入的位置
     * @param e 需要插入的数据
     */
    // 时间复杂度： O(n)
    void add(int index, E e) {
        // 检查 index 的合法性
        if (index < 0 || index > size)
            throw "add failed, index must >= 0 and <= size";

        Node<E>* prev = dummyHead;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        prev->next = new Node<E>(e, prev->next);

        size++;

    }

    /**
     * 删除链表的头节点
     * @return
     */
    // 时间复杂度： O(1)
    E removeFirst() {
        return remove(0);
    }

    // 时间复杂度： O(n)
    E removeLast() {
        return remove(size - 1);
    }

    /**
     * 删除指定索引的节点，并返回删除的节点的值
     * @param index
     * @return
     */
    // 时间复杂度： O(n)
    E remove(int index) {
        // 检查 index 的合法性
        if (index < 0 || index >= size) {
            throw "remove failed, index must >= 0 and < size";
        }

        Node<E>* prev = dummyHead;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node<E>* delNode = prev->next;
        prev->next = delNode->next;
        delNode->next = nullptr;

        size--;

        return delNode->e;
    }

    /**
     * 删除第一个值等于 e 的节点
     * @param e
     */
    void removeElement(E e) {
        if (dummyHead->next == nullptr)
            throw "removeElement failed, LinkedList is Empty";

        Node<E>* prev = dummyHead;
        Node<E>* curr = dummyHead->next;
        while (curr != nullptr) {
            if (curr->e == e) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        // bug 修复，需要先判断 curr
        // 如果 curr 为 null 的话，说明链表中不存在值等于 e 的节点
        if (curr != nullptr) {
            prev->next = curr->next;
            curr->next = nullptr;
        }
    }

    /**
     * 判断链表中是否存在指定元素
     * @param e
     * @return
     */
    // 时间复杂度： O(n)
    bool contains(E e) {
        Node<E>* curr = dummyHead->next;
        while (curr != nullptr) {
            // TODO：这里有 bug，不是所有类型的数据都有 == 这个操作的
            // 实际上除了 int 等基本类型外，其他类型都不支持 ==
            if (curr->e == e) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    string toString() {
        string res = "";
        Node<E>* curr = dummyHead->next;
        while (curr != nullptr) {
            res += curr->toString() + "=>";
            curr = curr->next;
        }
        res += "null";
        return res;
    }

};

/*
int main() {
    LinkedList<int>* ll = new LinkedList<int>();
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
}*/
