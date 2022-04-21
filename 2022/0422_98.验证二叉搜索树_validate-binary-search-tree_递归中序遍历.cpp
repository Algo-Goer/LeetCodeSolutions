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

// code1 中序遍历&递归 写法一

class Solution
{
public:
    long maxVal = LONG_MIN; // 中序遍历的当前最大值
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        if (!isValidBST(root->left))
            return false; // 先判断左子树是否是BST
        if (root->val <= maxVal)
            return false;   // 如果发现当前值小于等于之前最大值，说明中序遍历到的结果不是严格递增，不符合BST特点
        maxVal = root->val; // 更新中序遍历遇到的当前最大值
        if (!isValidBST(root->right))
            return false; // 再判断右子树是否是BST
        return true;
    }
};
// @lc code=end
