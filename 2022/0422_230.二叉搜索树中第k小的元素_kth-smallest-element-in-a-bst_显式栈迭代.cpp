/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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

// code1 中序遍历&显式栈/非递归&迭代

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> s;
        while (root || s.size() > 0)
        {
            while (root)
            {
                s.push(root);
                root = root->left; // 左
            }
            root = s.top();
            s.pop();
            --k;  // 相当于中
            if (k == 0)
                break;
            root = root->right; // 右
        }
        return root->val; 
    }
};
// @lc code=end
