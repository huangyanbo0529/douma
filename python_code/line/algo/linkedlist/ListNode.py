
class ListNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

    def toString(self):
        res = ""
        curr = self
        while curr:
            res += str(curr.val) + "->"
            curr = curr.next
        res += "null"
        return res


def fromArray(arr):
    if arr is None or len(arr) == 0:
        return None
    head = ListNode(val=arr[0])
    curr = head
    for i in range(1, len(arr)):
        curr.next = ListNode(val=arr[i])
        curr = curr.next
    return head


if __name__ == '__main__':
    head = fromArray([23, 12, 11, 34])
    print(head.toString())