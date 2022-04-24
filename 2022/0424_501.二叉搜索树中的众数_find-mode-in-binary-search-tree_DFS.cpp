/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
// code1 DFS递归&哈希&前序遍历
class Solution
{
public:
    int maxV = 0;
    void dfs(TreeNode *root, unordered_map<int, int> &mp, int &maxV)
    {
        if (root == NULL)
            return;
        mp[root->val]++;
        if (mp[root->val] > maxV)
            maxV = mp[root->val];
        dfs(root->left, mp, maxV);
        dfs(root->right, mp, maxV);
        return;
    }

    vector<int> findMode(TreeNode *root)
    {
        unordered_map<int, int> mp;
        vector<int> res;
        dfs(root, mp, maxV);
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it->second == maxV)
                res.push_back(it->first);
        }
        return res;
    }
};
// @lc code=end
