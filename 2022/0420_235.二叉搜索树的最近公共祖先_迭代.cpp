/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// code2 非递归

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            if (root->val > max(p->val, q->val))
                root = root->left;
            else if (root->val < min(p->val, q->val))
                root = root->right;
            else
                return root;
        }
        return root; // 不要漏，写成return nullptr;也可AC
    }
};
// @lc code=end
