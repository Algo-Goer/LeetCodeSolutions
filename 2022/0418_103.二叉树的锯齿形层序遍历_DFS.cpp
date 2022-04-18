/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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

// code2 先像[102]那样写DFS代码进行层序遍历，然后对ans中的奇数下标进行逆序

class Solution
{
public:
    void dfs(TreeNode *root, int level, vector<vector<int>> &ans)
    {
        if (!root)
            return;
        while (ans.size() <= level)
        {
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);
        dfs(root->left, level + 1, ans);
        dfs(root->right, level + 1, ans);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        dfs(root, 0, ans);
        for (int i = 1; i < ans.size(); i += 2)
        {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
// @lc code=end
