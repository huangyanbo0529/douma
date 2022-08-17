// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


const RED = true
const BLACK = false

class TreeNode {
    constructor(data) {
        this.data = data
        this.left = null
        this.right = null
        // 1. 在红黑树中，红色的节点代表的就是它和它的父亲在 2-3 树中是在融合在一起的
        // 2. 在 2-3 树中插入新建的节点的时候，都是先和叶子节点进行融合
        this.color = RED
    }
}

class RBTree {
    constructor(__comp) {
        this.root = null
        this.size = 0
        this.__comp = __comp
    }

    getSize() {
        return this.size;
    }

    isEmpty() {
        return this.size == 0;
    }

    // 判断一个节点是否是红色的
    isRED(node) {
        // 根据红黑树的定义，空节点的颜色是黑色的
        if (!node) {
            return BLACK
        }
        return node.color
    }

    //    node                    x
    //    /  \       左旋转      /   \
    //   T1   x     ------->  node  T3
    //       / \              /  \
    //      T2 T3            T1  T2
    leftRotate(node) {
        const x = node.right

        // 左旋
        node.right = x.left
        x.left = node

        x.color = node.color
        node.color = RED

        return x
    }

    // 颜色翻转
    flipColors(node) {
        node.color = RED;
        node.left.color = BLACK;
        node.right.color = BLACK;
    }

    //    node                    x
    //    /  \       右旋转      /   \
    //   x   T2     ------->   y   node
    //  / \                        /  \
    // y  T1                      T1  T2
    rightRotate(node) {
        const x = node.left
        // 右旋
        node.left = x.right
        x.right = node

        x.color = node.color
        node.color = RED

        return x
    }

    /*************************插入操作*******************************/
    // 时间复杂度：O(logn)
    add(e) {
        this.root = this.addR(this.root, e)
    }

    // 将节点 e 插入到以 node 为根节点的子树当中
    // 并返回插入节点后的二叉查找树的根节点
    addR(node, e) {
        // 1. 递归终止条件
        if (!node) {
            this.size++
            return new TreeNode(e)
        }

        // 2. 递归调用
        // bug 修复：插入的时候只考虑不相等的元素，相等的元素不做任何插入动作
        if (this.__comp(e, node.data) < 0) {
            node.left = this.addR(node.left, e)
        } else if (this.__comp(e, node.data) > 0) {
            node.right = this.addR(node.right, e)
        } else {
            return node
        }

        // 维护以 node 为根节点的子树的黑平衡
        if (this.isRED(node.right) && !this.isRED(node.left)) {
            node = this.leftRotate(node);
        }

        if (this.isRED(node.left) && this.isRED(node.left.left)) {
            node = this.rightRotate(node);
        }

        if (this.isRED(node.left) && this.isRED(node.right)) {
            this.flipColors(node);
        }

        return node
    }

    /*************************修改操作*******************************/
    // set 方法会破坏二叉查找树的性质

    /*************************查询操作*******************************/
    contains(target) {
        const node = this.find(target)
        if (!node) return false
        return true
    }

    // 时间复杂度：O(logn)
    find(target) {
        return this.findR(this.root, target)
    }

    findR(node, target) {
        if (!node) return null
        if (this.__comp(target, node.data) == 0) {
            return node
        } else if (this.__comp(target, node.data) < 0) {
            return this.findR(node.left, target)
        } else {
            return this.findR(node.right, target)
        }
    }

    // 中序遍历
    // 时间复杂度：O(n), n 表示二叉树节点个数
    // 空间复杂度：O(n)
    inOrder() {
        const res = []

        const inOrderR = (node) => {
            if (!node) return
            inOrderR(node.left)
            res.push(node.data)
            inOrderR(node.right)
        }

        inOrderR(this.root)
        return res
    }

    // 注意，这里只保留中序遍历，其他的遍历省略了。。。。

    // 时间复杂度：O(logn)
    minValue() {
        if (!this.root) throw new Error("tree is null")
        return this.minValueR(this.root).data
    }

    minValueR(node) {
        if (!node.left) return node
        return this.minValueR(node.left)
    }

    // 时间复杂度：O(logn)
    maxValue() {
        if (!this.root) throw new Error("tree is null")
        return this.maxValueR(this.root).data
    }

    maxValueR(node) {
        if (!node.right) return node
        return this.maxValueR(node.right)
    }

    /*************************删除操作*******************************/
    // 时间复杂度：O(logn)
    removeMin() {
        if (!this.root) throw new Error("tree is null")
        const res = this.minValue()
        this.root = this.removeMinR(this.root)
        return res
    }

    // 删除以  node 为根节点的子树的最小节点
    // 并返回删除完最小节点的子树的根节点
    removeMinR(node) {
        if (!node.left) {
            const rightNode = node.right
            node.right = null
            this.size--
            return rightNode
        }
        const leftRoot = this.removeMinR(node.left)
        node.left = leftRoot
        return node
    }

    // 时间复杂度：O(logn)
    removeMax() {
        if (!this.root) throw new Error("tree is null")
        const res = this.maxValue()
        this.root = this.removeMaxR(this.root)
        return res
    }

    removeMaxR(node) {
        if (!node.right) {
            const leftNode = node.left
            node.left = null
            this.size--
            return leftNode
        }
        const rightRoot = this.removeMaxR(this.root)
        node.right = rightRoot
        return node
    }

    // 时间复杂度：O(logn)
    remove(e) {
        this.root = this.removeR(this.root, e)
    }

    // 在以 node 为根节点的子树中删除节点 e
    // 并且返回删除后的子树的根节点
    removeR(node, e) {
        if (!node) return null

        if (this.__comp(e, node.data) < 0) {
            node.left = this.removeR(node.left, e)
            return node
        } else if (this.__comp(e, node.data) > 0) {
            node.right = this.removeR(node.right, e)
            return node
        } else {
            // 要删除的节点就是 node
            if (!node.left) {
                const rightNode = node.right
                node.right = null
                this.size--
                return rightNode
            }

            if (!node.right) {
                const leftNode = node.left
                node.left = null
                this.size--
                return leftNode
            }

            // node 的 left 和 right 都不为空
            const successor = this.minValueR(node.right)

            successor.right = this.removeMinR(node.right)
            successor.left = node.left

            node.left = null
            node.right = null

            // bug 修复：这里不用修改 size 了，因为在上面的 removeMin 已经修改过了
            // size--;
            return successor;
        }
    }
}

function test() {
    const bst = new BSTR((x, y) => x - y)
    bst.add(33)
    bst.add(22)
    bst.add(66)
    bst.add(12)
    bst.add(35)
    bst.add(70)
    bst.add(34)
    bst.add(50)
    bst.add(68)
    bst.add(99)

    console.log(bst.inOrder())
    console.log(bst.contains(34))

    console.log(bst.minValue())
    console.log(bst.maxValue())

    console.log(bst.removeMin())
    console.log(bst.inOrder())

    console.log(bst.removeMin())
    console.log(bst.inOrder())

    bst.remove(66)
    console.log(bst.inOrder())
}

test()