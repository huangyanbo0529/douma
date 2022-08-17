/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include "BST.h"
using namespace std;

template <typename E, typename Compare>
class BSTR {
private:
    TreeNode<E>* root;
    int size;
    Compare __comp;

public:
    BSTR(Compare __comp): __comp(__comp) {
        this->root = nullptr;
        this->size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    /*************************插入操作*******************************/
    // 时间复杂度：O(logn)
    void add(E e) {
        root = addR(root, e);
    }

    // 将节点 e 插入到以 node 为根节点的子树当中
    // 并返回插入节点后的二叉查找树的根节点
    TreeNode<E>* addR(TreeNode<E>* node, E e) {
        // 1. 递归终止条件
        if (node == nullptr) {
            size++;
            return new TreeNode<E>(e);
        }

        // 2. 递归调用
        // bug 修复：插入的时候只考虑不相等的元素，相等的元素不做任何插入动作
        if (__comp(e, node->data) < 0) {
            node->left = addR(node->left, e);
        } else if (__comp(e, node->data) > 0) {
            node->right = addR(node->right, e);
        }

        return node;
    }

    /*************************查询操作*******************************/
    bool contains(E target) {
        TreeNode<E>* node = find(target);
        if (node == nullptr) return false;
        return true;
    }
    // 时间复杂度：O(logn)
    TreeNode<E>* find(E target) {
        return findR(root, target);
    }

    TreeNode<E>* findR(TreeNode<E>* node, E target) {
        if (node == nullptr) return nullptr;
        if (__comp(target, node->data) == 0) {
            return node;
        } else if (__comp(target, node->data) < 0) {
            return findR(node->left, target);
        } else {
            return findR(node->right, target);
        }
    }

    // 中序遍历
    // 时间复杂度：O(n), n 表示二叉树节点个数
    // 空间复杂度：O(n)
    void inOrderHelp(TreeNode<int>* node, vector<int>& res) {
        // 退出边界条件
        if (node == nullptr) return;
        // 先中序遍历左子树
        inOrderHelp(node->left, res);
        // 然后访问当前节点
        res.push_back(node->data);
        // 最后中序遍历右子树
        inOrderHelp(node->right, res);
    }

    // 中序遍历(递归)
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> inOrder() {
        vector<int> res;
        if (root == nullptr) return res;
        inOrderHelp(root, res);
        return res;
    }
    // 这里省略掉其他前中后序遍历，以及层序遍历...........

    // 时间复杂度：O(logn)
    E minValue() {
        if (root == nullptr) {
            throw "tree is null";
        }
        return minValueR(root)->data;
    }

    TreeNode<E>* minValueR(TreeNode<E>* node) {
        if (node->left == nullptr) return node;
        return minValueR(node->left);
    }

    // 时间复杂度：O(logn)
    E maxValue() {
        if (root == nullptr) {
            throw "tree is null";
        }
       return maxValueR(root)->data;
    }

    TreeNode<E>* maxValueR(TreeNode<E>* node) {
        if (node->right == nullptr) return node;
        return maxValueR(node->right);
    }

    /*************************删除操作*******************************/
    // 时间复杂度：O(logn)
    E removeMin() {
        if (root == nullptr) {
            throw "tree is null";
        }
        E res = minValue();
        root = removeMinR(root);
        return res;
    }

    // 删除以  node 为根节点的子树的最小节点
    // 并返回删除完最小节点的子树的根节点
    TreeNode<E>* removeMinR(TreeNode<E>* node) {
        if (node->left == nullptr) {
            TreeNode<E>* rightNode = node->right;
            node->right = nullptr;
            size--;
            return rightNode;
        }

        TreeNode<E>* leftRoot = removeMinR(node->left);
        node->left = leftRoot;

        return node;
    }

    // 时间复杂度：O(logn)
    E removeMax() {
        if (root == nullptr) {
            throw "tree is null";
        }

        E res = maxValue();
        root = removeMaxR(root);
        return res;
    }

    TreeNode<E>* removeMaxR(TreeNode<E>* node) {
        if (node->right == nullptr) {
            TreeNode<E>* leftNode = node->left;
            node->left = nullptr;
            size--;
            return leftNode;
        }

        TreeNode<E>* rightRoot = removeMaxR(node->right);
        node->right = rightRoot;

        return node;
    }

    // 时间复杂度：O(logn)
    void remove(E e) {
        if (root == nullptr) return;

        root = removeR(root, e);
    }

    // 在以 node 为根节点的子树中删除节点 e
    // 并且返回删除后的子树的根节点
    TreeNode<E>* removeR(TreeNode<E>* node, E e) {
        if (node == nullptr) return nullptr;

        if (__comp(e, node->data) < 0) {
            node->left = removeR(node->left, e);
            return node;
        } else if (__comp(e, node->data) > 0) {
            node->right = removeR(node->right, e);
            return node;
        } else {
            // 要删除的节点就是 node
            if (node->left == nullptr) {
                TreeNode<E>* rightNode = node->right;
                node->right = nullptr;
                size--;
                return rightNode;
            }

            if (node->right == nullptr) {
                TreeNode<E>* leftNode = node->left;
                node->left = nullptr;
                size--;
                return leftNode;
            }

            // node 的 left 和 right 都不为空
            TreeNode<E>* successor = minValueR(node->right);

            successor->right = removeMinR(node->right);
            successor->left = node->left;

            node->left = nullptr;
            node->right = nullptr;
            size--;
            return successor;
        }
    }
};
