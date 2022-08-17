/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

template <typename E>
struct TreeNode {
    E data;
    TreeNode* left;
    TreeNode* right;

    int height;

    TreeNode(E data): data(data), left(nullptr), right(nullptr), height(1) {}
};

template <typename E, typename Compare>
class AVLTree {
private:
    TreeNode<E>* root;
    int size;
    Compare __comp;

    int getHeight(TreeNode<E>* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int getBalanceFactor(TreeNode<E>* node) {
        if (node == nullptr) return 0;
        // 平衡因子等于左右子节点的高度差
        return getHeight(node->left) - getHeight(node->right);
    }

    // 对节点 y 进行向右旋转操作，返回旋转后新的根节点 x
    //        y                                    x
    //       / \                                 /   \
    //      x   T4        向右旋转 (y)          z       y
    //     / \          --------------->      / \     / \
    //    z   T3                            T1   T2 T3   T4
    //   / \
    // T1   T2
    TreeNode<E>* rightRotate(TreeNode<E>* y) {
        TreeNode<E>* x = y->left;
        TreeNode<E>* t3 = x->right;

        // 右旋转
        x->right = y;
        y->left = t3;

        // 更新 x 和 y 的高度
        // bug 修复，必须先要计算 y 节点的高度，然后才计算 x 节点的高度
        // 原因：上面的 x.left = y ，说明 y 是 x 的子节点，需要先计算子节点的高度，才能计算父节点高度
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        // 返回调整之后的根节点
        return x;
    }

    // 对节点y进行向左旋转操作，返回旋转后新的根节点x
    //    y                             x
    //  /  \                          /   \
    // T4   x      向左旋转 (y)       y     z
    //     / \   - - - - - - - ->   / \   / \
    //   T3  z                     T4 T3 T1 T2
    //      / \
    //     T1 T2
    TreeNode<E>* leftRotate(TreeNode<E>* y) {
        TreeNode<E>* x = y->right;
        TreeNode<E>* t3 = x->left;

        // 左旋转
        x->left = y;
        y->right = t3;

        // 更新 x 和 y 的高度
        // bug 修复，必须先要计算 y 节点的高度，然后才计算 x 节点的高度
        // 原因：上面的 x.left = y ，说明 y 是 x 的子节点，需要先计算子节点的高度，才能计算父节点高度
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        // 返回调整之后的根节点
        return x;
    }

public:
    AVLTree(Compare __comp): __comp(__comp) {
        this->root = nullptr;
        this->size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    // 判断一棵二叉树是否是二叉查找树
    bool isBST() {
        // 2. 先中序遍历二叉查找树，得到遍历的结果列表
        vector<E> res = inOrderR();
        int len = res.size();
        if (len <= 1) return true;

        // 然后判断结果列表是否是增序排列的
        for (int i = 1; i < len; ++i) {
            if (__comp(res[i], res[i - 1]) < 0) return false;
        }

        return true;
    }

    // 判断一棵树是否平衡
    bool isBalanced() {
        return isBalancedR(root);
    }

    bool isBalancedR(TreeNode<E>* node) {
        if (node == nullptr) return true;
        int balanceFactor = getBalanceFactor(node);
        if (abs(balanceFactor) > 1) return false;
        return isBalancedR(node->left) && isBalancedR(node->right);
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

        // 更新父亲节点的高度值
        // 父亲节点的高度值等于左右子节点最大的高度值再加上 1
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        // 计算每个父亲节点的平衡因子
        int balanceFactor = getBalanceFactor(node);
        // LL
        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
            // 处理左边不平衡，进行右旋转
            return rightRotate(node);
        }
        // RR
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
            // 处理右边不平衡，进行左旋转
            return leftRotate(node);
        }
        // LR
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
            // 先将 node.left 进行左旋，转成 LL
            node->left = leftRotate(node->left);
            // 然后对 node 进行右旋
            return rightRotate(node);
        }
        // RL
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
            // 先将 node.right 进行右旋，转成 RR
            node->right = rightRotate(node->right);
            // 再将 node 进行左旋
            return leftRotate(node);
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
        root = removeR(root, res);
        return res;
    }

    // 时间复杂度：O(logn)
    E removeMax() {
        if (root == nullptr) {
            throw "tree is null";
        }

        E res = maxValue();
        root = removeR(root, res);
        return res;
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

        TreeNode<E>* retNode;
        if (__comp(e, node->data) < 0) {
            node->left = removeR(node->left, e);
            retNode = node;
        } else if (__comp(e, node->data) > 0) {
            node->right = removeR(node->right, e);
            retNode = node;
        } else {
            // 要删除的节点就是 node
            if (node->left == nullptr) {
                TreeNode<E>* rightNode = node->right;
                node->right = nullptr;
                size--;
                // 注意：这里其实可以直接返回 retNode 的
                // 因为右子树是已经平衡了的，不需要再调整了
                // 这里不直接返回，是为了统一对 retNode 的处理
                retNode = rightNode;
            } else if (node->right == nullptr) {
                TreeNode<E>* leftNode = node->left;
                node->left = nullptr;
                size--;
                // 注意：这里其实可以直接返回 retNode 的
                // 因为左子树是已经平衡了的，不需要再调整了
                // 这里不直接返回，是为了统一对 retNode 的处理
                retNode = leftNode;
            } else {
                // node 的 left 和 right 都不为空
                TreeNode<E>* successor = minValueR(node->right);

                successor->right = removeR(node->right, successor->data);
                successor->left = node->left;

                node->left = nullptr;
                node->right = nullptr;
                // bug 修复，因为递归 remove 中已经进行了 size-- 了
                // 所以这里不需要了
                // size--;
                retNode = successor;
            }
        }
        // bug 修复：需要对 retNode 判空
        if (retNode == nullptr) return nullptr;

        // 平衡维护(retNode)
        // 更新父亲节点的高度值
        // 父亲节点的高度值等于左右子节点最大的高度值再加上 1
        retNode->height = max(getHeight(retNode->left),
                                  getHeight(retNode->right)) + 1;
        // 计算每个父亲节点的平衡因子
        int balanceFactor = getBalanceFactor(retNode);
        // LL
        if (balanceFactor > 1 && getBalanceFactor(retNode->left) >= 0) {
            // 处理左边不平衡，进行右旋转
            return rightRotate(retNode);
        }
        // RR
        if (balanceFactor < -1 && getBalanceFactor(retNode->right) <= 0) {
            // 处理右边不平衡，进行左旋转
            return leftRotate(retNode);
        }
        // LR
        if (balanceFactor > 1 && getBalanceFactor(retNode->left) < 0) {
            // 先将 retNode.left 进行左旋，转成 LL
            retNode->left = leftRotate(retNode->left);
            // 然后对 retNode 进行右旋
            return rightRotate(retNode);
        }
        // RL
        if (balanceFactor < -1 && getBalanceFactor(retNode->right) > 0) {
            // 先将 retNode.right 进行右旋，转成 RR
            retNode->right = rightRotate(retNode->right);
            // 再将 retNode 进行左旋
            return leftRotate(retNode);
        }
        return retNode;
    }
};

static int intCompare(int x, int y) {
    return x - y;
}

int main() {
    AVLTree<int, decltype(&intCompare)> avlTree(intCompare);
    avlTree.add(9);
    avlTree.add(10);
    avlTree.add(11);
    avlTree.add(13);

    cout << "是否是二叉查找树：" + to_string(avlTree.isBST()) << endl;

    cout << "是否是平衡二叉树：" + to_string(avlTree.isBalanced()) << endl;

    return 0;
}