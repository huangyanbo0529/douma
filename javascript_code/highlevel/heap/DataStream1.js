// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


class Node {
    constructor(val) {
        this.val = val
        this.next = null
    }
}

class DataStream1 {
    constructor() {
        this.dummyNode = new Node(-1)
    }

    // O(n)
    add(val) {
        // 找到第一个比 val 小的节点
        let prev = this.dummyNode
        let curr = this.dummyNode.next
        while (curr) {
            if (curr.val < val) {
                break
            }
            prev = curr
            curr = curr.next
        }

        // 将元素添加到第一个比它小的节点的前面
        const newNode = new Node(val)
        newNode.next = curr
        prev.next = newNode
    }

    // O(n)
    removeMax() {
        if (!this.dummyNode.next) {
            throw new Error("removeMax 失败，因为数据流中没有元素")
        }
        // 保存需要返回的最大值 (头节点的值)
        const res = this.dummyNode.next.val;

        // 删除头节点
        const head = this.dummyNode.next;
        this.dummyNode.next = head.next;
        head.next = null;

        return res;
    }
}

function test() {
    const dataStream = new DataStream1()
    dataStream.add(3)
    console.log(dataStream.removeMax()) // 打印 3
    dataStream.add(6)
    dataStream.add(5)
    console.log(dataStream.removeMax()) // 打印 6
    dataStream.add(2)
    dataStream.add(1)
    console.log(dataStream.removeMax()) // 打印 5
}

test()