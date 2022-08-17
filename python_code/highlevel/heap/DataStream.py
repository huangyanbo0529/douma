# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class Node:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next


class DataStream:
    def __init__(self):
        self.dummy_node = Node(-1)

    # 时间复杂度：O(1)
    def add(self, val):
        new_node = Node(val)
        new_node.next = self.dummy_node.next
        self.dummy_node.next = new_node

    def removeMax(self):
        if not self.dummy_node.next:
            raise Exception("removeMax 失败，因为数据流中没有元素")
        # 遍历一遍链表，找到最大值所在的节点
        curr = self.dummy_node.next
        max_value_node = curr
        while curr:
            if curr.val > max_value_node.val:
                max_value_node = curr
            curr = curr.next

        # 找到最大值节点的前一个节点
        curr, max_value_node_prev = self.dummy_node.next, self.dummy_node
        while curr:
            if curr == max_value_node:
                break
            max_value_node_prev = curr
            curr = curr.next

        # 删除最大值所在的节点
        max_value_node_prev.next = max_value_node.next
        max_value_node.next = None

        return max_value_node.val


if __name__ == '__main__':
    ds = DataStream()
    ds.add(3)
    print(ds.removeMax())  # 打印 3
    ds.add(6)
    ds.add(5)
    print(ds.removeMax())  # 打印 6
    ds.add(2)
    ds.add(1)
    print(ds.removeMax())  # 打印 5
