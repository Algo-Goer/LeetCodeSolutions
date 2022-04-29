/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 递归+利用[104]求树最大深度
// 相关题[1522]
// 最大深度：从根节点到叶子节点最长路径上的节点数[104]
// 最大直径：任意两个节点最长的路径上的边数 = 某一个节点的左子树最大深度 + 右子树最大深度，因为是边数而非节点数，所以不用加1
// 比如示例中节点1的左子树最大深度2 + 右子树最大深度1 = 3
// 找出每一个节点的左子树最大深度+右子树最大深度
class Solution
{
public:
    int maxDepth(TreeNode *root)
    // [104] 二叉树的最大深度
    {
        if (!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int res = 0;
        if (!root)
            return res;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        res = max(left + right, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
        return res;
    }
};
// @lc code=end
