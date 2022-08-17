/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // BFS
    int maxDepth1(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            // 每处理一层，层数累加 1
            res++;
        }

        return res;
    }

    // DFS 前序遍历 - 迭代
    int maxDepth2(TreeNode* root) {
        if (!root) return {};

        int res;
        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, 1));
        while (!s.empty()) {
            pair<TreeNode*, int> curr = s.top();
            s.pop();
            TreeNode *currNode = curr.first;
            int currLevel = curr.second;

            res = max(res, currLevel);

            if (currNode->right) s.push(make_pair(currNode->right, currLevel + 1));
            if (currNode->left) s.push(make_pair(currNode->left, currLevel + 1));
        }

        return res;
    }

    // DFS 前序遍历 - 递归
    int maxDepth3(TreeNode* root) {
        if (!root) return 0;
        preOrder(root, 1);
        return res;
    }

private:
    int res = 0;
    void preOrder(TreeNode* node, int currLevel) {
        if (!node) return;

        res = max(res, currLevel);

        preOrder(node->left, currLevel + 1);
        preOrder(node->right, currLevel + 1);
    }

public:
    // DFS 后序遍历 - 递归
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int leftMaxDepth = maxDepth(root->left);
        int rightMaxDepth = maxDepth(root->right);

        return max(leftMaxDepth, rightMaxDepth) + 1;
    }

};