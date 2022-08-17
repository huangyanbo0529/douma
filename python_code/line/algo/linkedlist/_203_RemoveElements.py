from line.algo.linkedlist.ListNode import ListNode


class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy_node = ListNode(-1)
        dummy_node.next = head

        prev, curr = dummy_node, head
        while curr:
            if curr.val == val:
                prev.next = curr.next
            else:
                prev = curr
            curr = prev.next

        return dummy_node.next