

class Node:
    def __init__(self, e, prev=None, next=None):
        self.e = e
        self.prev = prev
        self.next = next


class DoubleLinkedList:
    def __init__(self):
        self.first = None
        self.last = None
        self.size = 0

    def getSize(self):
        return self.size

    def isEmpty(self):
        return self.size == 0

    # 找到指定 index 的节点
    # 时间复杂度是 O(n)
    def node(self, index):
        if index < 0 or index >= self.size:
            return None

        # 如果 index 小于链表长度的一半，则从 first 开始遍历查找
        if index < self.size // 2:
            curr = self.first
            for i in range(0, index):
                curr = curr.next
        # 如果 index 大于等于链表长度的一半，则从 last 开始遍历查找
        else:
            curr = self.last
            for i in range(0, self.size - index - 1):
                curr = curr.prev

        return curr

    """
        查询操作
    """
    def get(self, index):
        curr = self.node(index)
        if not curr:
            raise Exception("index failed, index must >= 0 and < size")
        return curr.e

    def getFirst(self):
        return self.first

    def getLast(self):
        return self.last

    """
        修改操作
    """
    def set(self, index, e):
        curr = self.node(index)
        if not curr:
            raise Exception("index failed, index must >= 0 and < size")
        curr.e = e

    """
        新增操作
    """
    def addFirst(self, e):
        new_node = Node(e)
        if not self.first:
            # 如果头节点为空，说明链表中没有一个节点
            # 那么新插入的节点既是头节点，又是尾节点
            self.last = new_node
        else:
            # 将新节点作为头节点
            new_node.next = self.first
            self.first.prev = new_node
        self.first = new_node
        self.size += 1

    def addLast(self, e):
        new_node = Node(e)
        if not self.last:
            # 如果尾节点为空，说明链表中没有一个节点
            # 那么新插入的节点既是头节点，又是尾节点
            self.first = new_node
        else:
            # 将新节点作为尾节点
            new_node.prev = self.last
            self.last.next = new_node
        self.last = new_node
        self.size += 1

    def add(self, index, e):
        if index < 0 or index >= self.getSize():
            raise Exception("add failed, require index >= 0 && index < size")
        if index == self.size:
            self.addLast(e)
        elif index == 0:
            self.addFirst(e)
        else:
            # 1. 找到要插入的位置，并记住这个位置的节点
            old_node = self.node(index)
            prev = old_node.prev

            # 2. 新建节点，将它的 next 指向 oldNode，将它的 prev 指向 oldNode.prev
            new_node = Node(e, prev, old_node)

            # 3. 将新建节点设置为 oldNode 的 prev
            old_node.prev = new_node

            # 4. 将新建节点设置 oldNode 之前的 prev 的 next
            prev.next = new_node

            self.size += 1

    """
        删除操作
    """
    def removeFirst(self):
        if not self.first:
            raise Exception("不能再空链表中删除节点")
        e = self.first.e
        # 拿到头节点的下一个节点
        second_node = self.first.next
        # 如果 next 为空，说明整个链表只有一个节点
        if not second_node:
            self.first = None
            self.last = None
        else:
            # 将头节点从链表中断开
            self.first.next = None
            second_node.prev = None
            # 将 second_node 设置为头节点
            self.first = second_node
        self.size -= 1
        return e

    def removeLast(self):
        if not self.last:
            raise Exception("不能再空链表中删除节点")
        e = self.last.e
        # 拿到尾节点的前一个节点
        prev_node = self.last.prev
        # 如果 prev_node 为空，说明整个链表只有一个节点
        if not prev_node:
            self.last = None
            self.first = None
        else:
            # 将尾节点从链表中断开
            self.last.prev = None
            prev_node.next = None
            # 将 prev 设置为尾节点
            self.last = prev_node
        self.size -= 1
        return e

    def remove(self, index):
        if index < 0 or index >= self.getSize():
            raise Exception("remove failed, require index >= 0 && index < size")
        if index == 0:
            return self.removeFirst()
        elif index == self.size - 1:
            return self.removeLast()

        # 1. 找到要删除的节点
        del_node = self.node(index)
        e = del_node.e

        # 2. 记住要删除节点的 prev 和 next 节点
        prev_node, next_node = del_node.prev, del_node.next

        # 3. 将删除节点的前后节点联系起来
        prev_node.next = next_node
        next_node.prev = prev_node

        # 4. 将删除节点从链表中断开
        del_node.next = None
        del_node.prev = None

        self.size -= 1
        return e




