/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <stack>
#include <iostream>
#include "BST.h"

using namespace std;

// 因为 BST 中节点存储的元素的类型是 E，并且节点中的元素的值必须可比较
// 为了支持任意类型的数据比较，我们需要传入一个自定义比较函数
// 这个比较函数是针对类型 E 自定义的
template <typename E, typename Compare>
class BST {
private:
    TreeNode<E>* root;
    int size;
    Compare __comp;

public:
    BST(Compare __comp): __comp(__comp) {
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
        if (root == nullptr) {
            root = new TreeNode<E>(e);
        } else {
            TreeNode<E>* curr = root;
            while (curr != nullptr) {
                if (__comp(e, curr->data) == 0) {
                    return;
                } else if (__comp(e, curr->data) < 0 && curr->left == nullptr) {
                    curr->left = new TreeNode<E>(e);
                    size++;
                    return;
                } else if (__comp(e, curr->data) > 0 && curr->right == nullptr) {
                    curr->right = new TreeNode<E>(e);
                    size++;
                    return;
                }

                if (e < curr->data) {
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
        }
    }

    /*************************查询操作*******************************/
    bool contains(E target) {
        TreeNode<E>* node = find(target);
        if (node == nullptr) return false;
        return true;
    }
    // 时间复杂度：O(logn)
    TreeNode<E>* find(E target) {
        if (root == nullptr) return nullptr;

        TreeNode<E>* curr = root;
        while (curr != nullptr) {
            if (__comp(target, curr->data) == 0) {
                return curr;
            } else if (__comp(target, curr->data) < 0) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return nullptr;
    }

    // 中序遍历
    // 时间复杂度：O(n), n 表示二叉树节点个数
    // 空间复杂度：O(n)
    vector<E> inOrder() {
        vector<E> res;
        if (root == nullptr) return res;

        stack<TreeNode<E>*> s;
        TreeNode<E>* curr = root;
        while (curr != nullptr || !s.empty()) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            TreeNode<E>* node = s.top();
            s.pop();
            res.push_back(node->data);

            curr = node->right;
        }

        return res;
    }
    // 这里省略掉其他前中后序遍历，以及层序遍历...........

    /*
        *************************修改操作*******************************
        // set 方法会破坏二叉查找树的性质
        // 可以使用先删除再添加的方式，来代替 set 操作，这样的时间复杂度为 O(logn)
        public void set(E src, E target) {
            if (contains(target)) return;
            TreeNode srcNode = find(src);
            srcNode.data = target;
        }
     **/

    // 时间复杂度：O(logn)
    E minValue() {
        if (root == nullptr) {
            throw "tree is null";
        }
        TreeNode<E>* min = root;
        while (min->left != nullptr) {
            // 一直往左子节点走
            min = min->left;
        }
        return min->data;
    }
    // 时间复杂度：O(logn)
    E maxValue() {
        if (root == nullptr) {
            throw "tree is null";
        }
        TreeNode<E>* max = root;
        while (max->right != nullptr) {
            // 一直往右子节点走
            max = max->right;
        }
        return max->data;
    }

    /*************************删除操作*******************************/
    // 时间复杂度：O(logn)
    E removeMin() {
        if (root == nullptr) {
            throw "tree is null";
        }

        TreeNode<E>* min = root;
        TreeNode<E>* parent = nullptr;
        while (min->left != nullptr) {
            parent = min;
            min = min->left;
        }

        if (parent == nullptr) { // 删除根节点
            root = root->right;
        } else {
            parent->left = min->right;
        }
        // bug 修复：统一释放 min 节点
        min->right = nullptr;

        size--;
        return min->data;
    }

    // 时间复杂度：O(logn)
    E removeMax() {
        if (root == nullptr) {
            throw "tree is null";
        }

        TreeNode<E>* max = root;
        TreeNode<E>* parent = nullptr;
        while (max->right != nullptr) {
            parent = max;
            max = max->right;
        }

        if (parent == nullptr) { // 删除根节点
            root = root->left;
        } else {
            parent->right = max->left;
        }
        // bug 修复：统一释放 max 节点
        max->left = nullptr;

        size--;
        return max->data;
    }

    // 时间复杂度：O(logn)
    void remove(E e) {
        if (root == nullptr) return;

        TreeNode<E>* curr = root;
        TreeNode<E>* parent = nullptr;
        // 找到要删除的节点
        while (curr != nullptr && __comp(e, curr->data) != 0) {
            parent = curr;
            if (__comp(e, curr->data) < 0) curr = curr->left;
            else curr = curr->right;
        }
        // 如果没有找到需要删除的元素，则直接返回
        if (curr == nullptr) return;

        if (curr->left != nullptr && curr->right != nullptr) {
            // 1. 找到 curr 的右子树的最小值节点
            TreeNode<E>* min = curr->right;
            TreeNode<E>* minParent = curr;
            while (min->left != nullptr) {
                minParent = min;
                min = min->left;
            }
            // 2. 覆盖需要删除节点的值为最小值
            curr->data = min->data;

            // 3. 删除最小值节点
            curr = min;
            parent = minParent;
        }

        // 删除节点是叶子节点或者仅有一个子树
        TreeNode<E>* child; // 用于存储 需要删除节点 的子节点
        if (curr->left != nullptr) {
            child = curr->left;
             // 注意：删除的是根节点的话，也需要将当前节点的 left 置空
            curr->left = nullptr;
        } else if (curr->right != nullptr) {
            child = curr->right;
             // 注意：删除的是根节点的话，也需要将当前节点的 right 置空
            curr->right = nullptr;
        } else {
            child = nullptr;
        }

        if (parent == nullptr) {
            root = child;
        } else if (curr == parent->left) {
            parent->left = child;
        } else if (curr == parent->right) {
            parent->right = child;
        }

        // bug 修复：需要维护好 size
        size--;
    }

    void remove1(E e) {
        if (root == nullptr) return;

        TreeNode<E>* curr = root;
        TreeNode<E>* parent = nullptr;
        // 找到要删除的节点
        while (curr != nullptr && __comp(e, curr->data) != 0) {
            parent = curr;
            if (__comp(e, curr->data) < 0) curr = curr->left;
            else curr = curr->right;
        }
        // 如果没有找到需要删除的元素，则直接返回
        if (curr == nullptr) return;

        if (curr->left == nullptr && curr->right == nullptr) { // 删除叶子节点
            if (parent == nullptr) { // 删除根节点
                root = nullptr;
            } else if (curr == parent->left) {
                parent->left = nullptr;
            } else if (curr == parent->right) {
                parent->right = nullptr;
            }
        } else if (curr->left != nullptr && curr->right == nullptr) { // 只有左子树
            if (parent == nullptr) { // 删除根节点
                root = curr->left;
                 // 注意：删除的是根节点的话，也需要将当前节点的 left 置空
                 curr->left = nullptr;
            } else if (curr == parent->left) {
                parent->left = curr->left;
                curr->left = nullptr;
            } else if (curr == parent->right) {
                parent->right = curr->left;
                curr->left = nullptr;
            }
        } else if (curr->left == nullptr && curr->right != nullptr) { // 只有右子树
            if (parent == nullptr) { // 删除根节点
                root = curr->right;
                 // 注意：删除的是根节点的话，也需要将当前节点的 right 置空
                 curr.right = nullptr;
            } else if (curr == parent->left) {
                parent->left = curr->right;
                curr->right = nullptr;
            } else if (curr == parent->right) {
                parent->right = curr->right;
                curr->right = nullptr;
            }
        } else if (curr->left != nullptr && curr->right != nullptr) {
            // 1. 找到 curr 的右子树的最小值节点
            TreeNode<E>* min = curr->right;
            TreeNode<E>* minParent = curr;
            while (min->left != nullptr) {
                minParent = min;
                min = min->left;
            }
            // 2. 覆盖需要删除节点的值为最小值
            curr->data = min->data;

            // 3. 删除最小值节点
            // 先拿到要删除 min 节点的右子树
            TreeNode<E>* right = min->right;
            // bug 修复：这里删除 min 节点，需要区分 min 是父亲节点的右子节点还是左子节点
            // 要删除 min 节点是父亲节点的右子节点
            if (minParent->right == min) {
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
                minParent->right = right;
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
                minParent->left = right;
            }
            // 删掉 min 的右子树，这样可以使得 min 节点从树中断开
            min->right = nullptr;
        }

        // bug 修复：需要维护好 size
        size--;
    }
};
