from line.algo.linkedlist import ListNode


def count(head):
    """
    计算一个链表中包含多少个节点数
    :param head: 表头
    :return: 链表包含的节点数
    """
    if head is None:
       return 0
    cnt, curr = 0, head
    while curr:
        cnt, curr = cnt + 1, curr.next
    return cnt

# Python 的 for 循环不太好遍历链表

def countTarget(head, target):
    """
    计算链表等于目标值的节点个数
    :param head: 表头
    :param target: 目标值
    :return: 等于目标值的节点个数
    """
    if head is None:
        return 0
    cnt, curr = 0, head
    while curr:
        if curr.val == target:
            cnt = cnt + 1
        curr = curr.next
    return cnt


if __name__ == '__main__':
    head = ListNode.fromArray([23, 12, 11, 34, 12])
    print(countTarget(head, 12))