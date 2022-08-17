/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }

        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        root->right = left;
        root->left = right;

        return root;
    }
};