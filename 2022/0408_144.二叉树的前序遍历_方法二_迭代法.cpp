/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
/*
迭代/非递归算法1
二叉树前序遍历：root->left->right
*/
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        TreeNode *p = root;
        stack<TreeNode *> s; // 定义栈指针s
        while (p != nullptr || !s.empty())
        {
            while (p != nullptr)
            {
                res.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            if (!s.empty())
            {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return res;
    }
};
// @lc code=end
