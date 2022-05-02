/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
// code2 迭代
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->val > val) // val应该加入到左子树
            {
                if (cur->left)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if (cur->right)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
// @lc code=end
