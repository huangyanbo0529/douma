/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    // 每个节点包含：
    // 1. 一个字符
    char c;
    // 2. 若干个子节点
    vector<Node*> children;

    // 标识，这个节点是否是一个单词最后一个字符
    bool isWord = false;

    Node(char c): c(c) {}
};

class Trie {
private:
    Node* root;

    int containsChar(vector<Node*> children, char c) {
        for (int i = 0; i < children.size(); i++) {
            if (children[i]->c == c) {
                return i;
            }
        }
        return -1;
    }

public:
    Trie() {
        root = new Node('/');
    }

    // 添加单词
    // O(n)
    void add(string word) {
        Node* curr = root;
        for (char c : word) { // O(n)
            // 1. 先从子节点中查找是否包含当前字符 c
            int index = containsChar(curr->children, c);
            if (index == -1) {
                curr->children.push_back(new Node(c));
                index = curr->children.size() - 1;
            }
            curr = curr->children[index];
        }
        curr->isWord = true;
    }

    // 判断是否包含指定的单词
    // O(n)
    bool contains(string word) {
        Node* curr = root;
        for (char c : word) { // O(n)
            // 1. 先从子节点中查找是否包含当前字符 c
            int index = containsChar(curr->children, c);
            if (index == -1) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isWord;
    }
};

int main() {
    Trie trie;
    trie.add("big");
    trie.add("pat");
    trie.add("bigger");
    trie.add("dog");
    trie.add("door");

    cout << trie.contains("dog") << endl;

    return 0;
}