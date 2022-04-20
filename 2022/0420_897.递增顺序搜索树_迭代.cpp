/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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

// code2 Iterative

class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        vector<int> v;
        
        if (!root)
            return nullptr;
        stack<TreeNode *> s;
        while (root || !s.empty())
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            if (!s.empty())
            {
                root = s.top();
                s.pop();
                v.push_back(root->val);
                root = root->right;
            }
        }
        
        TreeNode *newRoot = new TreeNode(v[0]);
        TreeNode *cur = newRoot;
        for (int i = 1; i < v.size(); ++i)
        {
            cur->right = new TreeNode(v[i]);
            cur = cur->right;
        }
        return newRoot;
    }
};
// @lc code=end
