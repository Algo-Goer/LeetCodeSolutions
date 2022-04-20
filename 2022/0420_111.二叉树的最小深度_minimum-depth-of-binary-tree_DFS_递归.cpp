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

// code1 DFS/递归

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        // root为空
        if (!root)
            return 0;
        // 左右孩子都为空，说明到达叶子结点，直接返回1即可
        if (root->left == NULL && root->right == NULL)
            return 1;
        int ans = INT_MAX;
        if (root->left)
            ans = min(ans, minDepth(root->left));
        if (root->right)
            ans = min(ans, minDepth(root->right));
        return ans + 1;
    }
};
// @lc code=end
