/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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

// code2 非递归/迭代/显式栈

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> stk;
        TreeNode *ptr = root;
        TreeNode *ptr2; // 最近被访问过的结点，用作标志
        do
        {
            while (ptr) // 向左走到尽头，左孩子指针入栈
            {
                stk.push(ptr);
                ptr = ptr->left;
            }
            ptr2 = nullptr;
            while (!stk.empty())
            {
                ptr = stk.top();
                if (ptr->right == nullptr || ptr->right == ptr2) // 右孩子为空或已经访问过
                {
                    // 访问当前根结点
                    ans.push_back(ptr->val);
                    ptr2 = ptr;
                    stk.pop();
                }
                else
                {
                    // 右子树非空且未被遍历
                    ptr = ptr->right; // 向右一步
                    break; // 没有break会超时
                }
            }
        } while (!stk.empty());
        return ans;
    }
};
// @lc code=end
