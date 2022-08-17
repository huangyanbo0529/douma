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

class DataStream1 {
private:
    Node* dummyNode;

public:
    DataStream1() {
        this->dummyNode = new Node(-1);
    }

    // O(1)
    void add(int val) {
        // 找到第一个比 val 小的节点
        Node* prev = dummyNode;
        Node* curr = dummyNode->next;
        while (curr != nullptr) {
            if (curr->val < val) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        // 将元素添加到第一个比它小的节点的前面
        Node* newNode = new Node(val);
        newNode->next = curr;
        prev->next = newNode;
    }

    // O(n)
    int removeMax() {
        if (dummyNode->next == nullptr)
            throw "removeMax 失败，因为数据流中没有元素";

        // 保存需要返回的最大值 (头节点的值)
        int res = dummyNode->next->val;

        // 删除头节点
        Node* head = dummyNode->next;
        dummyNode->next = head->next;
        head->next = nullptr;

        return res;
    }
};


int main() {
    DataStream1 dataStream;
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