// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var invertTree = function(root) {
    if (!root || (!root.left && !root.right)) {
        return root
    }
    const left = invertTree(root.left)
    const right = invertTree(root.right)

    root.left = right
    root.right = left
    return root
};