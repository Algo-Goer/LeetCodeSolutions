/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

// code1 跟[100]一样的思路，DFS/递归

class Solution
{
public:
    bool isMirror(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        else if (!p || !q)
            return false;
        else if (p->val != q->val)
            return false;
        else
            return isMirror(p->left, q->right) && isMirror(p->right, q->left); // 镜像，别写反
    }
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root, root);
    }
};
// @lc code=end
