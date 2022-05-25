/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        if (root->left && root->left->val != root->val) return false;
        if (root->right && root->right->val != root->val) return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
// @lc code=end

