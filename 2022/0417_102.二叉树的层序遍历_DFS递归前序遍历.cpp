/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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

// code2 DFS&递归：前序遍历，参数加layer

class Solution
{
public:
    void dfs(TreeNode *root, int layer, vector<vector<int>> &res)
    {
        if (!root)
            return;
        while (res.size() <= layer)
        {
            res.push_back(vector<int>());
        }
        res[layer].push_back(root->val);
        dfs(root->left, layer + 1, res);
        dfs(root->right, layer + 1, res);
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
};
// @lc code=end
