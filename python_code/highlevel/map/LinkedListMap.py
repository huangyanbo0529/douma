# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class Node:
    def __init__(self, key=None, value=None, next=None):
        self.key = key
        self.value = value
        self.next = next

    def toString(self):
        return str(self.key) + "->" + str(self.value)


class LinkedListMap:
    def __init__(self, __equal):
        self.dummyHead = Node()
        self.__size = 0
        self.__equal = __equal

    def size(self):
        return self.__size

    def isEmpty(self):
        return self.__size == 0

    def add(self, key, value):
        # 1. 找到 key 对应的 value 所在的节点
        curr = self.getNode(key)

        # 2. 如果 curr 为空的话，说明 Map 中还没有这个键值对
        if not curr:
            # 直接将键值对插入头节点即可
            self.dummyHead.next = Node(key, value, self.dummyHead.next)
            self.__size += 1
        else:
            # 键值对已经存在，那么更新 value
            curr.value = value

    def getNode(self, key):
        curr = self.dummyHead.next
        while curr:
            if self.__equal(key, curr.key):
                break
            curr = curr.next
        return curr

    def remove(self, key):
        # 1. 找到需要删除的节点的前一个节点
        prev, curr = self.dummyHead, self.dummyHead.next
        while curr:
            if self.__equal(curr.key, key):
                break
            prev = curr
            curr = curr.next

        # 2. 如果需要删除的节点不为空，则删除节点，并返回删除节点的值
        if curr:
            prev.next = curr.next
            curr.next = None
            self.__size -= 1
            return curr.value
        return None

    def set(self, key, new_value):
        curr = self.getNode(key)
        if curr:
            curr.value = new_value
        else:
            raise Exception("没有对应的 key ：{}".format(key))

    def get(self, key):
        node = self.getNode(key)
        return node.value if node else None

    def containsKey(self, key):
        node = self.getNode(key)
        return node
