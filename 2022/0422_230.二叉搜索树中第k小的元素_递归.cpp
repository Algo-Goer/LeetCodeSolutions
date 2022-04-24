/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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

// code2 中序遍历&递归

class Solution
{
public:
    int res;
    int count;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left); // 左
        count -= 1;          // 相当于中
        if (count == 0)
        {
            res = root->val;
            return;
        }
        inorder(root->right); // 右
    }
    int kthSmallest(TreeNode *root, int k)
    {
        count = k;
        inorder(root);
        return res;
    }
};
// @lc code=end
