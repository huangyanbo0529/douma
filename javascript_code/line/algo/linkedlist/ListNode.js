
class ListNode {
    constructor(val, next) {
        this.val = val
        this.next = next
    }

    toString() {
        let res = ""
        let curr = this
        while (curr != null) {
            res += `${curr.val} -> `
            curr = curr.next
        }
        res += "null"
        return res
    }
}

const fromArray = function (arr) {
    if (arr == null || arr.length == 0) return null
    const head = new ListNode(arr[0])
    let curr = head
    for (let i = 1; i < arr.length; i++) {
        curr.next = new ListNode(arr[i])
        curr = curr.next
    }
    return head
}

// 测试
//head = fromArray([23, 12, 11, 34])
//console.log(head.toString())