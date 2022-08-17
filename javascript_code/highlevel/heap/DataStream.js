// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


class Node {
    constructor(val) {
        this.val = val
        this.next = null
    }
}

class DataStream {
    constructor() {
        this.dummyNode = new Node(-1)
    }

    // O(1)
    add(val) {
        const newNode = new Node(val)
        newNode.next = this.dummyNode.next
        this.dummyNode.next = newNode
    }

    // O(n)
    removeMax() {
        if (!this.dummyNode.next) {
            throw new Error("removeMax 失败，因为数据流中没有元素")
        }
        // 遍历一遍链表，找到最大值所在的节点
        let curr = this.dummyNode.next
        let maxValueNode = curr
        while (curr) {
            if (curr.val > maxValueNode.val) {
                maxValueNode = curr
            }
            curr = curr.next
        }

        // 找到最大值节点的前一个节点
        curr = this.dummyNode.next
        let maxValueNodePrev = this.dummyNode
        while (curr) {
            if (curr == maxValueNode) {
                break;
            }
            maxValueNodePrev = curr
            curr = curr.next
        }

        // 删除最大值所在的节点
        maxValueNodePrev.next = maxValueNode.next
        maxValueNode.next = null

        return maxValueNode.val
    }
}

function test() {
    const dataStream = new DataStream()
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