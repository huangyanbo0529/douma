# 抖码算法，让算法学习变得简单有趣
# 作者：老汤

# 表示跳表的高度，包括原始链表这一层
import random

MAX_LEVEL = 16

class Node:
    def __init__(self, data):
        self.data = data
        self.nextNodes = [None] * MAX_LEVEL
        # 记录这个节点维护的索引节点的最大高度
        self.maxIndexLevel = 0


class SkipList:
    def __init__(self, __comp):
        # 表示当前跳表最大的高度 (包含了原始链表层，所以默认初始值是 1)
        self.levelCount = 1
        self.dummyHead = Node(-1)
        self.__comp = __comp

    def contains(self, e):
        return self.get(e)

    def get(self, e):
        curr = self.dummyHead
        # 从最高一层往下一层一层的寻找查找元素所在的区间
        for i in range(self.levelCount - 1, -1, -1):
            while curr.nextNodes[i] and self.__comp(curr.nextNodes[i].data, e) < 0:
                curr = curr.nextNodes[i]

        if curr.nextNodes[0] and self.__comp(curr.nextNodes[0].data, e) == 0:
            return curr.nextNodes[0]

        return None

    # 随机 level 次，如果是奇数层数 +1，防止伪随机
    def randomLevel(self):
        level = 1
        for i in range(1, MAX_LEVEL):
            if random.randint(0, MAX_LEVEL) % 2 == 1:
                level += 1
        return level

    def add(self, e):
        # 维护一层索引
        level = self.randomLevel() if self.dummyHead.nextNodes[0] else 1
        # 先将两层的前一个节点都初始化为虚拟头节点
        prevNodes = [None] * level
        for i in range(level):
            prevNodes[i] = self.dummyHead

        # 1. 找到节点要插入的位置的前一个节点 prev
        prev = self.dummyHead
        for i in range(self.levelCount - 1, -1, -1):
            while prev.nextNodes[i] and self.__comp(prev.nextNodes[i].data, e) < 0:
                prev = prev.nextNodes[i]
            # 维护每一层的前一个节点
            if i < level:
                prevNodes[i] = prev

        # 2. 在每一层的正确的位置插入新节点
        new_node = Node(e)
        new_node.maxIndexLevel = level
        for i in range(level):
            new_node.nextNodes[i] = prevNodes[i].nextNodes[i]
            prevNodes[i].nextNodes[i] = new_node

        # 更新链表的高度
        if self.levelCount < level:
            self.levelCount = level

    def remove(self, e):
        # 1. 找到需要删除节点的前一个节点，以及删除节点对应的索引节点的前一个索引节点
        prevNodes = [None] * self.levelCount
        prev = self.dummyHead
        for i in range(self.levelCount - 1, -1, -1):
            while prev.nextNodes[i] and self.__comp(prev.nextNodes[i].data, e) < 0:
                prev = prev.nextNodes[i]
            prevNodes[i] = prev

        # 2. 对每一层进行删除节点
        # 先判断节点是否存在，存在的话才执行删除
        if prev.nextNodes[0] and self.__comp(prev.nextNodes[0].data, e) == 0:
            # 对每一层进行删除节点
            for i in range(self.levelCount - 1, 0, -1):
                del_node = prevNodes[i].nextNodes[i]
                if del_node and self.__comp(del_node.data, e) == 0:
                    prevNodes[i].nextNodes[i] = del_node.nextNodes[i]
                    del_node.nextNodes[i] = None
