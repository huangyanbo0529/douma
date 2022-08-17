/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <stack>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

template <typename E>
struct TreeNode {
    E data;
    TreeNode<E>* left;
    TreeNode<E>* right;

    TreeNode(E data) : data(data), left(nullptr), right(nullptr) {}
};

// 前序遍历
// 时间复杂度：O(n), n 表示二叉树节点个数
// 空间复杂度：O(n)
static vector<int> preOrder(TreeNode<int>* root) {
    vector<int> res;
    if (root == nullptr) return res;

    stack<TreeNode<int>*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode<int>* curr = s.top();
        s.pop();
        res.push_back(curr->data);
        if (curr->right != nullptr) s.push(curr->right);
        if (curr->left != nullptr) s.push(curr->left);
    }

    return res;
}

static void preOrderHelp(TreeNode<int>* node, vector<int>& res) {
    // 退出边界条件
    if (node == nullptr) return;
    // 先访问当前节点
    res.push_back(node->data);
    // 再前序遍历左子树
    preOrderHelp(node->left, res);
    // 最后前序遍历右子树
    preOrderHelp(node->right, res);
}

// 前序遍历(递归)
// 时间复杂度：O(n)
// 空间复杂度：O(n)
static vector<int> preOrderR(TreeNode<int>* root) {
    vector<int> res;
    if (root == nullptr) return res;
    preOrderHelp(root, res);
    return res;
}

// 中序遍历
// 时间复杂度：O(n), n 表示二叉树节点个数
// 空间复杂度：O(n)
static vector<int> inOrder(TreeNode<int>* root) {
    vector<int> res;
    if (root == nullptr) return res;

    stack<TreeNode<int>*> s;
    TreeNode<int>* curr = root;
    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        TreeNode<int>* node = s.top();
        s.pop();
        res.push_back(node->data);

        curr = node->right;
    }

    return res;
}

static void inOrderHelp(TreeNode<int>* node, vector<int>& res) {
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
static vector<int> inOrderR(TreeNode<int>* root) {
    vector<int> res;
    if (root == nullptr) return res;
    inOrderHelp(root, res);
    return res;
}

// 后序遍历
// 时间复杂度：O(n), n 表示二叉树节点个数
// 空间复杂度：O(n)
static vector<int> postOrder(TreeNode<int>* root) {
    vector<int> res;
    if (root == nullptr) return res;

    stack<TreeNode<int>*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode<int>* curr = s.top();
        s.pop();
        res.push_back(curr->data);
        if (curr->left != nullptr) s.push(curr->left);
        if (curr->right != nullptr) s.push(curr->right);
    }

    std::reverse(res.begin(), res.end());

    return res;
}

static void postOrderHelp(TreeNode<int>* node, vector<int>& res) {
    // 退出边界条件
    if (node == nullptr) return;
    // 先后序遍历左子树
    postOrderHelp(node->left, res);
    // 然后后中序遍历右子树
    postOrderHelp(node->right, res);
    // 最后访问当前节点
    res.push_back(node->data);
}

// 后序遍历(递归)
// 时间复杂度：O(n)
// 空间复杂度：O(n)
static vector<int> postOrderR(TreeNode<int>* root) {
    vector<int> res;
    if (root == nullptr) return res;
    postOrderHelp(root, res);
    return res;
}

// 层序遍历（一）
// 时间复杂度：O(n), n 表示二叉树节点个数
// 空间复杂度：O(n)
static vector<int> levelOrder_1(TreeNode<int>* root) {
    vector<int> res;
    if (root == nullptr) return res;

    // 用 c++ 内置的双端队列来达到单向队列的功能
    deque<TreeNode<int>*> q;
    q.push_back(root);

    while (!q.empty()) {
        // 每轮循环遍历处理一个节点
        TreeNode<int>* curr = q.front();
        q.pop_front();
        res.push_back(curr->data);
        // 将遍历处理的节点的左右子节点入队，等到后序的处理
        if (curr->left != nullptr) q.push_back(curr->left);
        if (curr->right != nullptr) q.push_back(curr->right);
    }

    return res;
}


// 层序遍历（二）
// 时间复杂度：O(n), n 表示二叉树节点个数
// 空间复杂度：O(n)
static vector<vector<int>> levelOrder_2(TreeNode<int>* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;

    // 也可以用 c++ 内置的队列的功能
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        // 每轮循环遍历处理一层的节点
        int size = q.size();
        vector<int> levelNodes;
        for (int i = 0; i < size; ++i) {
            TreeNode<int> *curr = q.front();
            q.pop();
            levelNodes.push_back(curr->data);
            // 将遍历处理的节点的左右子节点入队，等到后序的处理
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
        res.push_back(levelNodes);
    }

    return res;
}

int main() {
    TreeNode<int>* root = new TreeNode<int>(23);
    TreeNode<int>* node1 = new TreeNode<int>(34);
    TreeNode<int>* node2 = new TreeNode<int>(21);
    TreeNode<int>* node3 = new TreeNode<int>(99);
    TreeNode<int>* node4 = new TreeNode<int>(77);
    TreeNode<int>* node5 = new TreeNode<int>(90);
    TreeNode<int>* node6 = new TreeNode<int>(45);
    TreeNode<int>* node7 = new TreeNode<int>(60);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node3->left = node4;
    node3->right = node5;
    node2->left = node6;
    node2->right = node7;

    vector<vector<int>> res = levelOrder_2(root);

    stringstream fmt;
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            fmt << to_string(res[i][j]) << ", ";
        }
        fmt << "\n";
    }
    cout << fmt.str() << endl;
    return 0;
}