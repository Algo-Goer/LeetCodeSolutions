/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
// DFS递归
class Solution
{
public:
    // 自定义函数求当前节点深度
    int Depth(TreeNode *root)
    {
        if (!root) return 0;
        int leftD = Depth(root->left);
        int rightD = Depth(root->right);
        return 1 + max(leftD, rightD);
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        if (!root) return NULL;
        int left = Depth(root->left); // 左子树深度
        int right = Depth(root->right); // 右子树深度
        if (left == right) // 如果左右两边深度相等，那么当前节点就是最近公共祖先
        {
            return root;
        }
        else if (left > right)
        {
            // 左边更深，就去左子树找
            return lcaDeepestLeaves(root->left);
        }
        else
            return lcaDeepestLeaves(root->right);
    }
};
// @lc code=end
