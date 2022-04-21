/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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

// code1 DFS/递归&中序遍历&双指针

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> res;
        inorder(root, res);
        int l = 0;
        int r = res.size() - 1;
        while (l < r)
        {
            int tmp = res[l] + res[r];
            if (tmp == k)
                return true;
            else if (tmp < k)
                l++;
            else
                r--;
        }
        return false;
    }
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        if (root->left)
            inorder(root->left, res);
        res.push_back(root->val);
        if (root->right)
            inorder(root->right, res);
    }
};
// @lc code=end
