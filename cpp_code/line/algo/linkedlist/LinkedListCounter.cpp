/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int val) : val(val), next(nullptr) {}
};

/**
 * 计算一个链表中包含多少个节点数
 * @param head  表头
 * @return  链表包含的节点数
 */
static int count(ListNode* head) {
    if (head == nullptr) return 0;
    int cnt = 0;
    ListNode* curr = head;
    // 使用 while 循环，遍历整个链表
    while (curr != nullptr) {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

static int countFor(ListNode* head) {
    if (head == nullptr) return 0;
    int cnt = 0;
    // 使用 for 循环，遍历整个链表
    for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
        cnt++;
    }
    return cnt;
}

/**
     * 计算链表等于目标值的节点个数
     * @param head  表头
     * @param target 目标值
     * @return 等于目标值的节点个数
     */
int countTarget(ListNode* head, int target) {
    if (head == nullptr) return 0;
    int cnt = 0;
    ListNode* curr = head;
    // 使用 while 循环，遍历整个链表
    while (curr != nullptr) {
        if (curr->val == target) cnt++;
        curr = curr->next;
    }
    return cnt;
}