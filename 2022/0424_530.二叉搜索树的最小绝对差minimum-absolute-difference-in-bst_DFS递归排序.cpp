/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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

// 递归 类似[653]

class Solution
{
public:
    void dfs(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        res.push_back(root->val);
        if (root->left)
            dfs(root->left, res);
        if (root->right)
            dfs(root->right, res);
    }
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> res;
        dfs(root, res);
        int minV = INT_MAX;
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size() - 1; ++i)
        {
            minV = min(minV, res[i + 1] - res[i]);
        }
        return minV;
    }
};

// @lc code=end

