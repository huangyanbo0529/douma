/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(): val(), next() {}

    ListNode(int val): val(val), next(nullptr) {}
};

static bool cmp(ListNode* node1, ListNode* node2) {
    return node1->val > node2->val;
}

// 优先队列
// 时间复杂度：O(k*n*logk)
// 空间复杂度：O(k)
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return nullptr;
    // 使用自定义小顶堆
    priority_queue<ListNode*, vector<ListNode*>, decltype(&cmp)> pq(cmp);

    for (auto node : lists) {
        // bug 修复：防止链表为空
        if (node == nullptr) continue;
        pq.push(node);
    }

    ListNode dummyNode;
    ListNode* curr = &dummyNode;
    while (!pq.empty()) {
        ListNode* minNode = pq.top();
        pq.pop();
        curr->next = minNode;
        curr = curr->next;
        if (minNode->next != nullptr) {
            pq.push(minNode->next);
        }
    }

    return dummyNode.next;
}