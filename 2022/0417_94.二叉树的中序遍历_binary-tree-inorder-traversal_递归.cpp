/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

// code1 递归算法
class Solution
{
public:
    vector<int> res; // 必须写在外面，否则WA
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return res;
        inorderTraversal(root->left); // 先序遍历左子树
        res.push_back(root->val); // 将根结点压入结果集
        inorderTraversal(root->right);  // 先序遍历右子树
        return res;
    }
};
// @lc code=end
