// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


class TreeNode {
    constructor(key, value) {
        this.key = key
        this.value = value
        this.left = null
        this.right = null
    }
}

export class BSTMap {
    constructor(__comp) {
        this.root = null
        this.__size = 0
        this.__comp = __comp
    }

    size() {
        return this.__size;
    }

    isEmpty() {
        return this.__size == 0;
    }

    // 时间复杂度：O(logn)
    add(key, value) {
        this.root = this.addR(this.root, key, value)
    }

    addR(node, key, value) {
        // 1. 递归终止条件
        if (!node) {
            this.__size++
            return new TreeNode(key, value)
        }

        // 2. 递归调用
        // bug 修复：插入的时候只考虑不相等的元素，相等的元素不做任何插入动作
        if (this.__comp(key, node.key) < 0) {
            node.left = this.addR(node.left, key, value)
        } else if (this.__comp(key, node.key) > 0) {
            node.right = this.addR(node.right, key, value)
        }

        return node
    }

    // 时间复杂度：O(logn)
    remove(key) {
        const node = this.get(key)
        if (!node) return null
        this.root = this.removeR(this.root, key)
        return node.value
    }

    removeR(node, key) {
        if (!node) return null

        if (this.__comp(key, node.key) < 0) {
            node.left = this.removeR(node.left, key)
            return node
        } else if (this.__comp(key, node.key) > 0) {
            node.right = this.removeR(node.right, key)
            return node
        } else {
            // 要删除的节点就是 node
            if (!node.left) {
                const rightNode = node.right
                node.right = null
                this.__size--
                return rightNode
            }

            if (!node.right) {
                const leftNode = node.left
                node.left = null
                this.__size--
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

    minValueR(node) {
        if (!node.left) return node
        return this.minValueR(node.left)
    }

    removeMinR(node) {
        if (!node.left) {
            const rightNode = node.right
            node.right = null
            this.__size--
            return rightNode
        }
        const leftRoot = this.removeMinR(node.left)
        node.left = leftRoot
        return node
    }

    // set 方法会破坏二叉查找树的性质
    // TODO : 这样直接修改数据的话，会影响 BST 的性质，这里需要重构
    set(key, newValue) {
        const node = this.get(this.root, key);
        if (node == null) {
            throw new Error("没有对应的 key ：" + key);
        }
        node.value = newValue;
    }

    // 时间复杂度：O(logn)
    get(key) {
        const node = this.getR(this.root, key)
        return node == null ? null : node.value
    }

    getR(node, key) {
        if (!node) return null
        if (this.__comp(key, node.key) == 0) {
            return node
        } else if (this.__comp(key, node.key) < 0) {
            return this.getR(node.left, key)
        } else {
            return this.getR(node.right, key)
        }
    }

    contains(key) {
        const node = this.get(key)
        if (!node) return false
        return true
    }

}