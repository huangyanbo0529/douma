

/**
 * 计算一个链表中包含多少个节点数
 * @param head  表头
 * @return  number
 */
const count = function (head) {
    if (head == null) return 0
    let cnt = 0
    let curr = head
    // 使用 while 循环，遍历整个链表
    while (curr != null) {
        cnt++;
        curr = curr.next;
    }
    return cnt
}

const countFor = function (head) {
    if (head == null) return 0
    let cnt = 0
    // 使用 for 循环，遍历整个链表
    for (let curr = head; curr != null; curr = curr.next) {
        cnt++
    }
    return cnt
}


/**
 * 计算链表等于目标值的节点个数
 * @param head  表头
 * @param target 目标值
 * @return number
 */
const countTarget = function (head, target) {
    if (head == null) return 0;
    let cnt = 0;
    let curr = head;
    // 使用 while 循环，遍历整个链表
    while (curr != null) {
        if (curr.val == target) cnt++;
        curr = curr.next;
    }
    return cnt;
}