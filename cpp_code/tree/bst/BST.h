/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/
#ifndef CPP_CODE_BST_H
#define CPP_CODE_BST_H

template <typename E>
struct TreeNode {
    E data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(E data): data(data), left(nullptr), right(nullptr) {}
};

#endif //CPP_CODE_BST_H
