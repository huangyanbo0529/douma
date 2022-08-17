/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/
#include <iostream>
#include "Map.h"

using namespace std;

template<typename K, typename V>
struct TreeNode {
    K key;
    V* value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key, V* value): key(key), value(value), left(nullptr), right(nullptr) {}
};

template<typename K, typename V, typename Compare>
class BSTMap : public Map<K, V>{
private:
    TreeNode<K, V>* root;
    int __size;
    Compare __comp;

public:
    BSTMap(Compare __comp): __comp(__comp) {
        this->root = nullptr;
        this->__size = 0;
    }

    int size() {
        return __size;
    }

    bool isEmpty() {
        return __size == 0;
    }

    /*************************插入操作*******************************/
    // 时间复杂度：O(logn)
    void add(K key, V&& value) {
        root = addR(root, key, value);
    }

    // 将节点 e 插入到以 node 为根节点的子树当中
    // 并返回插入节点后的二叉查找树的根节点
    TreeNode<K, V>* addR(TreeNode<K, V>* node, K key, V &value) {
        // 1. 递归终止条件
        if (node == nullptr) {
            __size++;
            return new TreeNode<K, V>(key, &value);
        }

        // 2. 递归调用
        // bug 修复：插入的时候只考虑不相等的元素，相等的元素不做任何插入动作
        if (__comp(key, node->key) < 0) {
            node->left = addR(node->left, key, value);
        } else if (__comp(key, node->key) > 0) {
            node->right = addR(node->right, key, value);
        } else {
            node->value = &value;
        }

        return node;
    }

    /*************************查询操作*******************************/
    bool containsKey(K key) {
        V* node = get(key);
        if (node == nullptr) return false;
        return true;
    }
    // 时间复杂度：O(logn)
    V* get(K key) {
        TreeNode<K, V>* node = findR(root, key);
        return node == nullptr ? nullptr : node->value;
    }

    TreeNode<K, V>* findR(TreeNode<K, V>* node, K key) {
        if (node == nullptr) return nullptr;
        if (__comp(key, node->key) == 0) {
            return node;
        } else if (__comp(key, node->key) < 0) {
            return findR(node->left, key);
        } else {
            return findR(node->right, key);
        }
    }

    // bug: 这样直接修改数据的话，会影响 BST 的性质
    // TODO :需要修改为在设置新值后，重新调整 BST
    void set(K key, V&& newValue) {
        TreeNode<K, V>* node = findR(root, key);
        if (node == nullptr) {
            throw "没有对应的 key ：" + key;
        }
        node->value = &newValue;
    }


    // 时间复杂度：O(logn)
    V* minValue() {
        if (root == nullptr) {
            throw "tree is null";
        }
        return minValueR(root)->value;
    }

    TreeNode<K, V>* minValueR(TreeNode<K, V>* node) {
        if (node->left == nullptr) return node;
        return minValueR(node->left);
    }

    /*************************删除操作*******************************/

    // 删除以  node 为根节点的子树的最小节点
    // 并返回删除完最小节点的子树的根节点
    TreeNode<K, V>* removeMinR(TreeNode<K, V>* node) {
        if (node->left == nullptr) {
            TreeNode<K, V>* rightNode = node->right;
            node->right = nullptr;
            __size--;
            return rightNode;
        }

        TreeNode<K, V>* leftRoot = removeMinR(node->left);
        node->left = leftRoot;

        return node;
    }

    // 时间复杂度：O(logn)
    V* remove(K key) {
        V* value = get(key);
        if (value == nullptr) return nullptr;

        root = removeR(root, key);
        return value;
    }

    // 在以 node 为根节点的子树中删除节点 e
    // 并且返回删除后的子树的根节点
    TreeNode<K, V>* removeR(TreeNode<K, V>* node, K key) {
        if (node == nullptr) return nullptr;

        if (__comp(key, node->key) < 0) {
            node->left = removeR(node->left, key);
            return node;
        } else if (__comp(key, node->key) > 0) {
            node->right = removeR(node->right, key);
            return node;
        } else {
            // 要删除的节点就是 node
            if (node->left == nullptr) {
                TreeNode<K, V>* rightNode = node->right;
                node->right = nullptr;
                __size--;
                return rightNode;
            }

            if (node->right == nullptr) {
                TreeNode<K, V>* leftNode = node->left;
                node->left = nullptr;
                __size--;
                return leftNode;
            }

            // node 的 left 和 right 都不为空
            TreeNode<K, V>* successor = minValueR(node->right);

            successor->right = removeMinR(node->right);
            successor->left = node->left;

            node->left = nullptr;
            node->right = nullptr;

            return successor;
        }
    }
};

static bool intCompare(const int &a, const int &b) {
    return a - b;
}

int main() {
    BSTMap<int, int, decltype(&intCompare)> map(intCompare);
    map.add(10, 100);
    map.add(10, 3444);

    int* res = map.get(10);

    cout << *res << endl;

    return 0;
}