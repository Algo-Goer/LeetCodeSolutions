/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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

// code2 DFS/递归 写法二

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        // 根结点为空
        if (!root)
            return 0;
        // 根结点即叶子结点
        if (!root->left && !root->right)
            return 1;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (!root->left || !root->right)
            return left + right + 1; // left和right中有一个为0
        // 左右孩子均不空
        return min(left, right) + 1;
    }
};
// @lc code=end
