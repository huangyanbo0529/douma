// 抖码算法，让算法学习变的简单有趣
// 作者：老汤

class Node {
    constructor() {
        // 每个节点包含：
        // 1. 一个字符
        // 2. 若干个子节点
        // a-z 26 个字符
        // a -> 0, b -> 1.... z -> 26
        // a - a = 0
        // b - a = 1
        this.children = new Array(26).fill(null)
        // 标识，这个节点是否是一个单词最后一个字符
        this.isWord = false
    }
}

class Trie {

    /** Initialize your data structure here. */
    constructor() {
        this.root = new Node()
    }

    /** Inserts a word into the trie. */
    insert(word) {
        let curr = this.root
        for (const c of word) {
            // 1. 先从子节点中查找是否包含当前字符 c
            if (curr.children[c.charCodeAt(0) - 'a'.charCodeAt(0)] == null) {
                curr.children[c.charCodeAt(0) - 'a'.charCodeAt(0)] = new Node()
            }
            curr = curr.children[c.charCodeAt(0) - 'a'.charCodeAt(0)]
        }
        curr.isWord = true
    }

    /** Returns if the word is in the trie. */
    search(word) {
        let curr = this.root
        for (const c of word) {
            // 1. 先从子节点中查找是否包含当前字符 c
            if (curr.children[c.charCodeAt(0) - 'a'.charCodeAt(0)] == null) {
                return false
            }
            curr = curr.children[c.charCodeAt(0) - 'a'.charCodeAt(0)]
        }
        return curr.isWord
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    startsWith(prefix) {
        let curr = this.root
        for (const c of prefix) {
            // 1. 先从子节点中查找是否包含当前字符 c
            if (curr.children[c.charCodeAt(0) - 'a'.charCodeAt(0)] == null) {
                return false
            }
            curr = curr.children[c.charCodeAt(0) - 'a'.charCodeAt(0)]
        }
        return true
    }
}