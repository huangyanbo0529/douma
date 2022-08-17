/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
};

class DataStream {
private:
    Node* dummyNode;

public:
    DataStream() {
        this->dummyNode = new Node(-1);
    }

    // O(1)
    void add(int val) {
        Node* newNode = new Node(val);
        newNode->next = dummyNode->next;
        dummyNode->next = newNode;
    }

    // O(n)
    int removeMax() {
        if (dummyNode->next == nullptr)
            throw "removeMax 失败，因为数据流中没有元素";

        // 遍历一遍链表，找到最大值所在的节点
        Node* curr = dummyNode->next;
        Node* maxValueNode = curr;
        while (curr != nullptr) {
            if (curr->val > maxValueNode->val) {
                maxValueNode = curr;
            }
            curr = curr->next;
        }

        // 找到最大值节点的前一个节点
        curr = dummyNode->next;
        Node* maxValueNodePrev = dummyNode;
        while (curr != nullptr) {
            if (curr == maxValueNode) {
                break;
            }
            maxValueNodePrev = curr;
            curr = curr->next;
        }

        // 删除最大值所在的节点
        maxValueNodePrev->next = maxValueNode->next;
        maxValueNode->next = nullptr;

        return maxValueNode->val;
    }
};


int main() {
    DataStream dataStream;
    dataStream.add(3);
    cout << to_string(dataStream.removeMax()) << endl;

    dataStream.add(6);
    dataStream.add(5);
    cout << to_string(dataStream.removeMax()) << endl;

    dataStream.add(2);
    dataStream.add(1);
    cout << to_string(dataStream.removeMax()) << endl;

    return 0;
}