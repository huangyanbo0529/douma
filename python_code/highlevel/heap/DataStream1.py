# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class Node:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next


class DataStream:
    def __init__(self):
        self.dummy_node = Node(-1)

    # 时间复杂度：O(n)
    def add(self, val):
        # 找到第一个比 val 小的节点
        prev, curr = self.dummy_node, self.dummy_node.next
        while curr:
            if curr.val < val:
                break
            prev = curr
            curr = curr.next

        # 将元素添加到第一个比它小的节点的前面
        new_node = Node(val, curr)
        prev.next = new_node

    # O(1)
    def removeMax(self):
        if not self.dummy_node.next:
            raise Exception("removeMax 失败，因为数据流中没有元素")
        # 保存需要返回的最大值 (头节点的值)
        res = self.dummy_node.next.val

        # 删除头节点
        head = self.dummy_node.next
        self.dummy_node.next = head.next
        head.next = None

        return res


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
