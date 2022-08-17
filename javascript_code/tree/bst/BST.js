// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


class TreeNode {
    constructor(data) {
        this.data = data
        this.left = null
        this.right = null
    }
}

class BST {
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

    /*************************插入操作*******************************/
    // 时间复杂度：O(logn)
    add(e) {
        if (!this.root) {
            this.root = new TreeNode(e)
        } else {
            let curr = this.root
            while (curr) {
                if (this.__comp(e, curr.data) == 0) {
                    return
                } else if (this.__comp(e, curr.data) < 0 && !curr.left) {
                    curr.left = new TreeNode(e)
                    this.size++
                    return
                } else if (this.__comp(e, curr.data) > 0 && !curr.right) {
                    curr.right = new TreeNode(e)
                    this.size++
                    return
                }

                if (this.__comp(e, curr.data) < 0) {
                    curr = curr.left
                } else {
                    curr = curr.right
                }
            }
        }
    }

    /*************************修改操作*******************************/
    /**
    // set 方法会破坏二叉查找树的性质
    // 可以使用先删除再添加的方式，来代替 set 操作，这样的时间复杂度为 O(logn)
    public void set(E src, E target) {
        if (contains(target)) return;
        TreeNode srcNode = find(src);
        srcNode.data = target;
    }
    """
    **/

    /*************************查询操作*******************************/
    contains(target) {
        const node = this.find(target)
        if (!node) return false
        return true
    }

    // 时间复杂度：O(logn)
    find(target) {
        if (!this.root) return null
        let curr = this.root
        while (curr) {
            if (this.__comp(target, curr.data) == 0) {
                return curr
            } else if (this.__comp(target, curr.data) < 0) {
                curr = curr.left
            } else {
                curr = curr.right
            }
        }
        return null
    }

    // 中序遍历
    // 时间复杂度：O(n), n 表示二叉树节点个数
    // 空间复杂度：O(n)
    inOrder() {
        if (!this.root) return []

        const stack = [], res = []
        let curr = this.root
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

    // 注意，这里只保留中序遍历，其他的遍历省略了。。。。

    // 时间复杂度：O(logn)
    minValue() {
        if (!this.root) throw new Error("tree is null")
        let min = this.root
        while (min.left) {
            min = min.left
        }
        return min.data
    }

    // 时间复杂度：O(logn)
    maxValue() {
        if (!this.root) throw new Error("tree is null")
        let max = this.root
        while (max.right) {
            max = max.right
        }
        return max.data
    }

    /*************************删除操作*******************************/
    // 时间复杂度：O(logn)
    removeMin() {
        if (!this.root) throw new Error("tree is null")

        let min = this.root, parent = null
        while (min.left) {
            parent = min
            min = min.left
        }

        if (!parent) { // 删除根节点
            this.root = this.root.right
        } else {
            parent.left = min.right
        }

        // bug 修复：统一释放 min 节点
        min.right = null;

        this.size--;
        return min.data;
    }

    // 时间复杂度：O(logn)
    removeMax() {
        if (!this.root) throw new Error("tree is null")

        let max = this.root, parent = null
        while (max.right) {
            parent = max
            max = max.right
        }

        if (!parent) { // 删除根节点
            this.root = this.root.left
        } else {
            parent.right = max.left
        }

        // bug 修复：统一释放 max 节点
        max.left = null;

        this.size--;
        return max.data;
    }

    // 时间复杂度：O(logn)
    remove(e) {
        if (!this.root) return

        let curr = this.root, parent = null
        // 找到要删除的节点
        while (curr && this.__comp(e, curr.data) != 0) {
            parent = curr
            if (this.__comp(e, curr.data) < 0) curr = curr.left
            else curr = curr.right
        }
        // 如果没有找到需要删除的元素，则直接返回
        if (!curr) return

        if (curr.left && curr.right) {
            // 1. 找到 curr 的右子树的最小值节点
            let min = curr.right, minParent = curr
            while (min.left) {
                minParent = min
                min = min.left
            }
            // 2. 覆盖需要删除节点的值为最小值
            curr.data = min.data
            // 3. 删除最小值节点
            curr = min
            parent = minParent
        }

        // 删除节点是叶子节点或者仅有一个子树
        let child // 用于存储 需要删除节点 的子节点
        if (curr.left) {
            child = curr.left
             // 注意：删除的是根节点的话，也需要将当前节点的 left 置空
            curr.left = null
        } else if (curr.right) {
            child = curr.right
             // 注意：删除的是根节点的话，也需要将当前节点的 right 置空
            curr.right = null
        } else {
            child = null
        }

        if (!parent) {
            this.root = child
        } else if (curr = parent.left) {
            parent.left = child
        } else if (curr == parent.right) {
            parent.right = child
        }
        // bug 修复：需要维护好 size
        this.size--
    }

    remove1(e) {
        if (!this.root) return

        let curr = this.root, parent = null
        // 找到要删除的节点
        while (curr && this.__comp(e, curr.data) != 0) {
            parent = curr
            if (this.__comp(e, curr.data) < 0) curr = curr.left
            else curr = curr.right
        }
        // 如果没有找到需要删除的元素，则直接返回
        if (!curr) return

        if (curr.left == null && curr.right == null) { // 删除叶子节点
            if (parent == null) { // 删除根节点
                this.root = null;
            } else if (curr == parent.left) {
                parent.left = null;
            } else if (curr == parent.right) {
                parent.right = null;
            }
        } else if (curr.left != null && curr.right == null) { // 只有左子树
            if (parent == null) { // 删除根节点
                this.root = curr.left;
                 // 注意：删除的是根节点的话，也需要将当前节点的 left 置空
                 curr.left = null
            } else if (curr == parent.left) {
                parent.left = curr.left;
                curr.left = null;
            } else if (curr == parent.right) {
                parent.right = curr.left;
                curr.left = null;
            }
        } else if (curr.left == null && curr.right != null) { // 只有右子树
            if (parent == null) { // 删除根节点
                this.root = curr.right;
                 // 注意：删除的是根节点的话，也需要将当前节点的 right 置空
                 curr.right = null
            } else if (curr == parent.left) {
                parent.left = curr.right;
                curr.right = null;
            } else if (curr == parent.right) {
                parent.right = curr.right;
                curr.right = null;
            }
        } else if (curr.left != null && curr.right != null) {
            // 1. 找到 curr 的右子树的最小值节点
            let min = curr.right;
            let minParent = curr;
            while (min.left) {
                minParent = min;
                min = min.left;
            }
            // 2. 覆盖需要删除节点的值为最小值
            curr.data = min.data;

            // 3. 删除最小值节点
            // 先拿到要删除 min 节点的右子树
            const right = min.right;
            // bug 修复：这里删除 min 节点，需要区分 min 是父亲节点的右子节点还是左子节点
            // 要删除 min 节点是父亲节点的右子节点
            if (minParent.right == min) {
                /*
                比如我们要删除以下树的节点 66
                        33
                     /      \
                   22        66
                           /    \
                         35      70
                                   \
                                    99
                那么这个时候：minParent = 66，min = 70，即 min 是父亲节点的右子节点
                */
                // 将 min 的右子树挂到父亲节点的右子树中
                minParent.right = right;
            } else { // 要删除 min 节点是父亲节点的左子节点
                /*
                比如我们要删除以下树的节点 66
                        33
                     /      \
                   22        66
                           /    \
                         35      70
                               /   \
                             68     99
                               \
                                69
                那么这个时候：minParent = 70，min = 68，即 min 是父亲节点的左子节点
                */
                // 将 min 的右子树挂到父亲节点的左子树中
                minParent.left = right;
            }
            // 删掉 min 的右子树，这样可以使得 min 节点从树中断开
            min.right = null;
        }
        // bug 修复：需要维护好 size
        this.size--
    }
}

function test() {
    const bst = new BST((x, y) => x - y)
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