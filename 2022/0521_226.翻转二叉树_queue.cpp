/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
// Queue
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            // 执行力极强，一出队列就把事情做好
            swap(node->left, node->right);
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
        }
        return root;
    }
};
// @lc code=end

