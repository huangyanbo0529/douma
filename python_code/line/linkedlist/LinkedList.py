
class Node:
    def __init__(self, e, next=None):
        self.e = e
        self.next = next

    def toString(self):
        return str(self.e)


class LinkedList:
    def __init__(self):
        self.dummyHead = Node(-1)
        self.size = 0

    def getSize(self):
        return self.size

    def isEmpty(self):
        return self.size == 0

    """
        查询操作
    """
    # 查询指定索引的节点的值
    # 时间复杂度： O(n)
    def get(self, index):
        if index < 0 or index >= self.getSize():
            raise Exception("get failed, require index >= 0 && index < size")

        curr = self.dummyHead.next
        for i in range(0, index):
            curr = curr.next

        return curr.e

    # 时间复杂度： O(1)
    def getFirst(self):
        return self.get(0)

    def getLast(self):
        return self.get(self.size - 1)

    """
        修改操作
    """
    # 修改指定索引的节点元素
    # 时间复杂度： O(n)
    def set(self, index, e):
        if index < 0 or index >= self.getSize():
            raise Exception("set failed, require index >= 0 && index < size")

        curr = self.dummyHead.next
        for i in range(0, index):
            curr = curr.next

        curr.e = e

    """
        新增操作
    """
    # 在指定索引的位置插入新的节点
    # 时间复杂度： O(n)
    def add(self, index, e):
        if index < 0 or index > self.getSize():
            raise Exception("add failed, require index >= 0 && index < size")

        prev = self.dummyHead
        for i in range(0, index):
            prev = prev.next

        prev.next = Node(e, prev.next)
        self.size += 1

    # 在链表表头新增节点
    # 时间复杂度： O(1)
    def addFirst(self, e):
        self.add(0, e)

    # 在链表表尾新增节点
    # 时间复杂度： O(n)
    def addLast(self, e):
        self.add(self.size, e)

    """
        删除操作
    """
    # 删除指定索引的节点，并返回删除的节点的值
    # 时间复杂度： O(n)
    def remove(self, index):
        if index < 0 or index >= self.getSize():
            raise Exception("remove failed, require index >= 0 && index < size")

        prev = self.dummyHead
        for i in range(0, index):
            prev = prev.next

        del_node = prev.next
        prev.next = del_node.next
        del_node.next = None

        self.size -= 1
        return del_node.e

    # 时间复杂度： O(1)
    def removeFirst(self):
        return self.remove(0)

    # 时间复杂度： O(n)
    def removeLast(self):
        return self.remove(self.size - 1)

    # 删除第一个值等于 e 的节点
    # 时间复杂度： O(n)
    def removeElement(self, e):
        if self.dummyHead.next is None:
            raise Exception("removeElement failed, LinkedList is Empty")
        prev, curr = self.dummyHead, self.dummyHead.next
        while curr:
            if curr.e == e:
                break
            prev = curr
            curr = curr.next
        # bug 修复，需要先判断 curr
        # 如果 curr 为 None 的话，说明链表中不存在值等于 e 的节点
        if curr:
            prev.next = curr.next
            curr.next = None

    # 判断链表中是否存在指定元素
    # 时间复杂度： O(n)
    def contains(self, e):
        curr = self.dummyHead.next
        while curr:
            if curr.e == e:
                return True
            curr = curr.next
        return False

    def toString(self):
        res = ""
        curr = self.dummyHead.next
        while curr:
            res += curr.toString() + "=>"
            curr = curr.next
        res += "null"
        return res
