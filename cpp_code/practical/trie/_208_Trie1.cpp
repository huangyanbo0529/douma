

#include <vector>
#include <string>

using namespace std;

struct Node {
    // 每个节点包含：
    // 1. 一个字符
    // 2. 若干个子节点
    // a-z 26 个字符
    // a -> 0, b -> 1.... z -> 26
    // a - a = 0
    // b - a = 1
    vector<Node*> children;
    bool isWord;

    Node() {
        children = vector<Node*>(26);
        isWord = false;
    }
};

class Trie {
private:
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        this->root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new Node();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */