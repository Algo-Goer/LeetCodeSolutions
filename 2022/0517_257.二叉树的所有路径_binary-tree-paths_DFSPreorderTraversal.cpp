/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
// DFS Preorder Traversal
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        string str = "";
        dfs(res, str, root);
        return res;
    }

    // 自定义
    void dfs(vector<string> &res, string str, TreeNode *node)
    {
        if (node == NULL)
            return;
        if (node->left == NULL && node->right == NULL)
        {
            str += to_string(node->val);
            res.push_back(str);
            return;
        }
        str += to_string(node->val) + "->";
        dfs(res, str, node->left);
        dfs(res, str, node->right);
    }
};
// @lc code=end
