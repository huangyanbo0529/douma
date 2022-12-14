from line.algo.linkedlist.ListNode import ListNode


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy_node = ListNode(-1)
        dummy_node.next = head

        slow = fast = dummy_node
        while n >= 0:
            fast = fast.next
            n -= 1
        while fast:
            slow, fast = slow.next, fast.next

        del_node = slow.next
        slow.next = del_node.next
        del_node.next = None
        return dummy_node.next