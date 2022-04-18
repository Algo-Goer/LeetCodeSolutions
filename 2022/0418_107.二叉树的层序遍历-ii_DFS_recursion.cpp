/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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

// code2 先像[102]那样写DFS递归代码，然后对ans里的答案进行逆序排列

class Solution
{
public:
    void dfs(TreeNode *root, int layer, vector<vector<int>> &ans)
    {
        if (!root)
            return;
        while (ans.size() <= layer)
        {
            ans.push_back(vector<int>());
        }
        ans[layer].push_back(root->val);
        dfs(root->left, layer + 1, ans);
        dfs(root->right, layer + 1, ans);
    }
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        dfs(root, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
