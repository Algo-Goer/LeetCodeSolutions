/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
// code1 DFS recursion
class Solution
{
public:
    // 自定义函数前序遍历
    void preorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        res.push_back(root->val);
        preorder(root->left, res); // 递归左子节点
        preorder(root->right, res); // 递归右子节点
    }
    void flatten(TreeNode *root)
    {
        // 前序遍历，获取二叉树的所有节点
        vector<int> res;
        preorder(root, res);
        // 如果二叉树为空直接返回
        if (res.size() == 0)
            return;

        // 重新构造二叉树
        TreeNode *cur = root;
        for (int i = 1; i < res.size(); ++i)
        {
            cur->right = new TreeNode(res[i]);
            cur->left = NULL;
            cur = cur->right;
        }
    }
};
// @lc code=end
