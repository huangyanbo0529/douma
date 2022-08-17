/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <stack>
#include <iostream>
#include <sstream>

using namespace std;

static bool RED = true;
static bool BLACK = false;

template <typename E>
struct TreeNode {
    E data;
    TreeNode* left;
    TreeNode* right;

    bool color; // 颜色

    TreeNode(E data): data(data), left(nullptr), right(nullptr) {
        // 1. 在红黑树中，红色的节点代表的就是它和它的父亲在 2-3 树中是在融合在一起的
        // 2. 在 2-3 树中插入新建的节点的时候，都是先和叶子节点进行融合
        this->color = RED;
    }
};

template <typename E, typename Compare>
class RBTree {
private:
    TreeNode<E>* root;
    int size;
    Compare __comp;

    // 判断一个节点是否是红色的
    bool isRED(TreeNode<E>* node) {
        // 根据红黑树的定义，空节点的颜色是黑色的
        if (node == nullptr) return BLACK;
        return node->color;
    }

    //    node                    x
    //    /  \       左旋转      /   \
    //   T1   x     ------->  node  T3
    //       / \              /  \
    //      T2 T3            T1  T2
    TreeNode<E>* leftRotate(TreeNode<E>* node) {
        TreeNode<E>* x = node->right;

        // 左旋
        node->right = x->left;
        x->left = node;

        x->color = node->color;
        node->color = RED;

        return x;
    }

    // 颜色翻转
    void flipColors(TreeNode<E>* node) {
        node->color = RED;
        node->left->color = BLACK;
        node->right->color = BLACK;
    }

    //    node                    x
    //    /  \       右旋转      /   \
    //   x   T2     ------->   y   node
    //  / \                        /  \
    // y  T1                      T1  T2
    TreeNode<E>* rightRotate(TreeNode<E>* node) {
        TreeNode<E>* x = node->left;
        // 右旋
        node->left = x->right;
        x->right = node;

        x->color = node->color;
        node->color = RED;

        return x;
    }

public:
    RBTree(Compare __comp):  __comp(__comp) {
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
        // 保持根节点为黑色
        root->color = BLACK;
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
        } else {
            return node;
        }

        // 维护以 node 为根节点的子树的黑平衡
        if (isRED(node->right) && !isRED(node->left)) {
            node = leftRotate(node);
        }

        if (isRED(node->left) && isRED(node->left->left)) {
            node = rightRotate(node);
        }

        if (isRED(node->left) && isRED(node->right)) {
            flipColors(node);
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
    vector<int> inOrderR() {
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

        root - removeR(root, e);
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