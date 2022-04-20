/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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

// code1 自顶向下递归

class Solution
{
public:
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        else
        {
            return max(height(root->left), height(root->right)) + 1;
        }
    }
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        int left = height(root->left);
        int right = height(root->right);
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right); // 根结点左右子树高度差<=1且左子树是平衡二叉树且右子树也是平衡二叉树
    }
};
// @lc code=end
