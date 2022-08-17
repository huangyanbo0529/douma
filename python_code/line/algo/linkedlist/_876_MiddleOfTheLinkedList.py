from line.algo.linkedlist.ListNode import ListNode


class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if not head and not head.next:
            return head
        slow = fast = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        return slow