// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


class Node {
    constructor(c) {
        // 每个节点包含：
        // 1. 一个字符
        this.c = c
        // 2. 若干个子节点
        this.children = []
        // 标识，这个节点是否是一个单词最后一个字符
        this.isWord = false
    }
}

class Trie {
    constructor() {
        this.root = new Node('/')
    }

    containsChar(children, c) {
        for (let i = 0; i < children.length; i++) {
            if (children[i].c == c) {
                return i
            }
        }
        return -1
    }

    // 添加单词
    // O(n)
    add(word) {
        let curr = this.root
        for (const c of word) {
            let index = this.containsChar(curr.children, c)
            if (index == -1) {
                curr.children.push(new Node(c))
                index = curr.children.length - 1
            }
            curr = curr.children[index]
        }
        curr.isWord = true
    }

    // 判断是否包含指定的单词
    // O(n)
    contains(word) {
        let curr = this.root
        for (const c of word) {
            let index = this.containsChar(curr.children, c)
            if (index == -1) {
                return false
            }
            curr = curr.children[index]
        }
        return curr.isWord
    }
}

const trie = new Trie()
trie.add("big")
trie.add("pat")
trie.add("bigger")
trie.add("dog")
trie.add("door")

console.log(trie.contains("dog"))