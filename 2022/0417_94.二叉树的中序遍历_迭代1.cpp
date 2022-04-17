/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

// code2 非递归

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *ptr = root;
        while (!s.empty() || ptr != nullptr) // 扫描结点p的所有左下结点并入栈
        {
            while (ptr != nullptr)
            {
                s.push(ptr); // 入栈
                ptr = ptr->left;
            }
            // 考虑栈顶结点
            if (!s.empty())
            {
                // 出栈并访问
                ptr = s.top();
                s.pop();
                ans.push_back(ptr->val); // 相当于访问
                ptr = ptr->right;
            }
        }
        return ans;
    }
};
// @lc code=end
