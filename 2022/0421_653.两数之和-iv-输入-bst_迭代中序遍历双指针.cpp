/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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

// code2 显式栈/迭代&中序遍历&双指针

class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (!s.empty() || cur)
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            if (!s.empty())
            {
                cur = s.top();
                s.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> res;
        inorder(root, res);
        int l = 0;
        int r = res.size() - 1;
        while (l < r)
        {
            int tmp = res[l] + res[r];
            if (tmp == k)
                return true;
            else if (tmp < k)
                l++;
            else
                r--;
        }
        return false;
    }
};
// @lc code=end
