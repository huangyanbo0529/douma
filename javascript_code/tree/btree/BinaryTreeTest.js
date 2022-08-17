

class TreeNode {
    constructor(data) {
        this.data = data
        this.left = null
        this.right = null
    }
}

// 前序遍历
// 时间复杂度：O(n), n 表示二叉树节点个数
// 空间复杂度：O(n)
function preOrder(root) {
    if (!root) return []

    const stack = [], res = []
    stack.push(root)

    while (stack.length) {
        const curr = stack.pop()
        res.push(curr.data)
        if (curr.right) stack.push(curr.right)
        if (curr.left) stack.push(curr.left)
    }

    return res
}

// 前序遍历（递归）
// 时间复杂度：O(n), n 表示二叉树节点个数
// 空间复杂度：O(n)
function preOrderR(root) {
    const res = []

    const preOrder = (node) => {
        if (!node) return
        res.push(node.data)
        preOrder(node.left)
        preOrder(node.right)
    }

    preOrder(root)
    return res
}

// 中序遍历
// 时间复杂度：O(n), n 表示二叉树节点个数
// 空间复杂度：O(n)
function inOrder(root) {
    if (!root) return []

    const stack = [], res = []
    let curr = root
    while (curr || stack.length) {
        while (curr) {
            stack.push(curr)
            curr = curr.left
        }
        const node = stack.pop()
        res.push(node.data)
        curr = node.right
    }

    return res
}

// 中序遍历（递归）
// 时间复杂度：O(n), n 表示二叉树节点个数
// 空间复杂度：O(n)
function inOrderR(root) {
    const res = []

    const inOrder = (node) => {
        if (!node) return
        inOrder(node.left)
        res.push(node.data)
        inOrder(node.right)
    }

    inOrder(root)
    return res
}

// 后序遍历
// 时间复杂度：O(n), n 表示二叉树节点个数
// 空间复杂度：O(n)
function postOrder(root) {
    if (!root) return []

    const stack = [], res = []
    stack.push(root)

    while (stack.length) {
        const curr = stack.pop()
        res.push(curr.data)
        if (curr.left) stack.push(curr.left)
        if (curr.right) stack.push(curr.right)
    }
    res.reverse()
    return res
}

// 后序遍历（递归）
// 时间复杂度：O(n), n 表示二叉树节点个数
// 空间复杂度：O(n)
function postOrderR(root) {
    const res = []

    const postOrder = (node) => {
        if (!node) return
        postOrder(node.left)
        postOrder(node.right)
        res.push(node.data)
    }

    postOrder(root)
    return res
}

// 层序遍历
// 时间复杂度：O(n), n 表示二叉树节点个数
// 空间复杂度：O(n)
function levelOrder(root) {
    if (!root) return []
    const res = [], queue = []
    queue.push(root)
    while (queue.length) {
        // 每轮循环遍历处理一个节点
        const curr = queue.shift()
        res.push(curr.data)
        // 将遍历处理的节点的左右子节点入队，等到后序的处理
        if (curr.left) queue.push(curr.left);
        if (curr.right) queue.push(curr.right);
    }
    return res
}

// 层序遍历 2
// 时间复杂度：O(n), n 表示二叉树节点个数
// 空间复杂度：O(n)
function levelOrder_2(root) {
    if (!root) return []
    const res = [], queue = []
    queue.push(root)
    while (queue.length) {
        // 每轮循环遍历处理一层的节点
        const size = queue.length
        const levelNodes = []
        for (let i = 0; i < size; i++) {
            const curr = queue.shift()
            levelNodes.push(curr.data)
            // 将遍历处理的节点的左右子节点入队，等到后序的处理
            if (curr.left) queue.push(curr.left);
            if (curr.right) queue.push(curr.right);
        }
        res.push(levelNodes)
    }
    return res
}

function test() {
    const root = new TreeNode(23)
    const node1 = new TreeNode(34)
    const node2 = new TreeNode(21)
    const node3 = new TreeNode(99)
    const node4 = new TreeNode(77)
    const node5 = new TreeNode(90)
    const node6 = new TreeNode(45)
    const node7 = new TreeNode(60)

    root.left = node1
    root.right = node2
    node1.left = node3
    node3.left = node4
    node3.right = node5
    node2.left = node6
    node2.right = node7

    console.log(preOrder(root))
    console.log(preOrderR(root))
    console.log(inOrder(root))
    console.log(inOrderR(root))
    console.log(postOrder(root))
    console.log(postOrderR(root))
    console.log(levelOrder(root))
    console.log(levelOrder_2(root))
}

test()

