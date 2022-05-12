/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
// code2 Recursive DFS 递增思路
class Solution
{
public:
    bool dfs(TreeNode *root, int curSum, int targetSum)
    {
        if (!root->left && !root->right) // 叶子节点
            return root->val + curSum == targetSum;
        bool left, right = false;
        if (root->left)
            left = dfs(root->left, curSum + root->val, targetSum);
        if (root->right)
            right = dfs(root->right, curSum + root->val, targetSum);
        return left || right;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;
        return dfs(root, 0, targetSum);
    }
};
// @lc code=end
