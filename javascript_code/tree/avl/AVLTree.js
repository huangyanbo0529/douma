// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


class TreeNode {
    constructor(data) {
        this.data = data
        this.left = null
        this.right = null
        this.height = 1
    }
}

class AVLTree {
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

    getHeight(node) {
        if (!node) return 0
        return node.height
    }

    getBalanceFactor(node) {
        if (!node) return 0
        // 平衡因子等于左右子节点的高度差
        return this.getHeight(node.left) - this.getHeight(node.right)
    }

    // 判断一棵二叉树是否是二叉查找树
    isBST() {
        // 先中序遍历二叉查找树，得到遍历的结果列表
        const res = this.inOrder()
        if (res.length <= 1) {
            return true
        }

        // 然后判断结果列表是否是增序排列的
        for (let i = 1; i < res.length; i++) {
            if (this.__comp(res[i], res[i - 1]) < 0) {
                return false
            }
        }

        return true
    }

    // 判断一棵树是否平衡
    isBalanced() {
        return this.isBalancedR(this.root)
    }

    isBalancedR(node) {
        if (!node) return true
        const balanceFactor = this.getBalanceFactor(node)
        if (Math.abs(balanceFactor) > 1) return false
        return this.isBalancedR(node.left) && this.isBalancedR(node.right)
    }

    // 对节点 y 进行向右旋转操作，返回旋转后新的根节点 x
    //        y                                    x
    //       / \                                 /   \
    //      x   T4        向右旋转 (y)          z       y
    //     / \          --------------->      / \     / \
    //    z   T3                            T1   T2 T3   T4
    //   / \
    // T1   T2
    rightRotate(y) {
        const x = y.left
        const t3 = x.right

        // 右旋转
        x.right = y
        y.left = t3

        // 更新 x 和 y 的高度
        // bug 修复，必须先要计算 y 节点的高度，然后才计算 x 节点的高度
        // 原因：上面的 x.left = y ，说明 y 是 x 的子节点，需要先计算子节点的高度，才能计算父节点高度
        y.height = Math.max(this.getHeight(y.left), this.getHeight(y.right)) + 1
        x.height = Math.max(this.getHeight(x.left), this.getHeight(x.right)) + 1

        // 返回调整之后的根节点
        return x
    }

    // 对节点y进行向左旋转操作，返回旋转后新的根节点x
    //    y                             x
    //  /  \                          /   \
    // T4   x      向左旋转 (y)       y     z
    //     / \   - - - - - - - ->   / \   / \
    //   T3  z                     T4 T3 T1 T2
    //      / \
    //     T1 T2
    leftRotate(y) {
        const x = y.right
        const t3 = x.left

        // 左旋转
        x.left = y
        y.right = t3

        // 更新 x 和 y 的高度
        // bug 修复，必须先要计算 y 节点的高度，然后才计算 x 节点的高度
        // 原因：上面的 x.left = y ，说明 y 是 x 的子节点，需要先计算子节点的高度，才能计算父节点高度
        y.height = Math.max(this.getHeight(y.left), this.getHeight(y.right)) + 1
        x.height = Math.max(this.getHeight(x.left), this.getHeight(x.right)) + 1

        // 返回调整之后的根节点
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
        }

        // 更新父亲节点的高度值
        // 父亲节点的高度值等于左右子节点最大的高度值再加上 1
        node.height = Math.max(this.getHeight(node.left), this.getHeight(node.right)) + 1
        // 计算每个父亲节点的平衡因子
        const balanceFactor = this.getBalanceFactor(node)
        // LL
        if (balanceFactor > 1 && this.getBalanceFactor(node.left) >= 0) {
            // 处理左边不平衡，进行右旋转
            return this.rightRotate(node)
        }
        // RR
        if (balanceFactor < -1 && this.getBalanceFactor(node.right) <= 0) {
            // 处理右边不平衡，进行左旋转
            return this.leftRotate(node)
        }
        // LR
        if (balanceFactor > 1 && this.getBalanceFactor(node.left) < 0) {
            // 先将 node.left 进行左旋，转成 LL
            node.left = this.leftRotate(node.left)
            // 然后对 node 进行右旋
            return this.rightRotate(node)
        }
        // RL
        if (balanceFactor < -1 && this.getBalanceFactor(node.right) > 0) {
            // 先将 node.right 进行右旋，转成 RR
            node.right = this.rightRotate(node.right)
            // 再将 node 进行左旋
            return this.leftRotate(node)
        }
        return node;
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

        let retNode
        if (this.__comp(e, node.data) < 0) {
            node.left = this.removeR(node.left, e)
            retNode = node
        } else if (this.__comp(e, node.data) > 0) {
            node.right = this.removeR(node.right, e)
            retNode = node
        } else {
            // 要删除的节点就是 node
            if (!node.left) {
                const rightNode = node.right
                node.right = null
                this.size--
                // 注意：这里其实可以直接返回 retNode 的
                // 因为右子树是已经平衡了的，不需要再调整了
                // 这里不直接返回，是为了统一对 retNode 的处理
                retNode = rightNode
            }else if (!node.right) {
                const leftNode = node.left
                node.left = null
                this.size--
                // 注意：这里其实可以直接返回 retNode 的
                // 因为左子树是已经平衡了的，不需要再调整了
                // 这里不直接返回，是为了统一对 retNode 的处理
                retNode = leftNode
            } else {
                // node 的 left 和 right 都不为空
                const successor = this.minValueR(node.right)

                successor.right = this.removeMinR(node.right)
                successor.left = node.left

                node.left = null
                node.right = null

                // bug 修复，因为递归 remove 中已经进行了 size-- 了
                // 所以这里不需要了
                // size--;
                retNode = successor;
            }
        }
        // bug 修复：需要对 retNode 判空
        if (retNode == null) return null;

        // 平衡维护(retNode)
        // 更新父亲节点的高度值
        // 父亲节点的高度值等于左右子节点最大的高度值再加上 1
        retNode.height = Math.max(this.getHeight(retNode.left),
            this.getHeight(retNode.right)) + 1;
        // 计算每个父亲节点的平衡因子
        const balanceFactor = this.getBalanceFactor(retNode);
        // LL
        if (balanceFactor > 1 && this.getBalanceFactor(retNode.left) >= 0) {
            // 处理左边不平衡，进行右旋转
            return this.rightRotate(retNode);
        }
        // RR
        if (balanceFactor < -1 && this.getBalanceFactor(retNode.right) <= 0) {
            // 处理右边不平衡，进行左旋转
            return this.leftRotate(retNode);
        }
        // LR
        if (balanceFactor > 1 && this.getBalanceFactor(retNode.left) < 0) {
            // 先将 retNode.left 进行左旋，转成 LL
            retNode.left = this.leftRotate(retNode.left);
            // 然后对 retNode 进行右旋
            return this.rightRotate(retNode);
        }
        // RL
        if (balanceFactor < -1 && this.getBalanceFactor(retNode.right) > 0) {
            // 先将 retNode.right 进行右旋，转成 RR
            retNode.right = this.rightRotate(retNode.right);
            // 再将 retNode 进行左旋
            return this.leftRotate(retNode);
        }
        return retNode;
    }
}

function test() {
    const avl = new AVLTree((x, y) => x - y)
    avl.add(9)
    avl.add(10)
    avl.add(11)
    avl.add(13)


    console.log(avl.isBST())
    console.log(avl.isBalanced())
}

test()