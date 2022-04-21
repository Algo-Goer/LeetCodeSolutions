/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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

// code2 中序遍历&递归 写法二

class Solution
{
public:
    // inorder traversal
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    bool isValidBST(TreeNode *root)
    {
        vector<int> res;
        inorder(root, res);
        for (int i = 1; i < res.size(); ++i)
        {
            if (res[i] <= res[i - 1])
                return false;
        }
        return true;
    }
};
// @lc code=end
