/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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

// code3 Stack/迭代

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        else if (!p || !q)
            return false;
        stack<TreeNode *> s1, s2;
        s1.push(p);
        s2.push(q);
        while (!s1.empty() && !s2.empty())
        {
            TreeNode *p1 = s1.top();
            s1.pop();
            TreeNode *p2 = s2.top();
            s2.pop();
            if (p1->val != p2->val)
                return false;
            auto l1 = p1->left, r1 = p1->right, l2 = p2->left, r2 = p2->right;
            if ((l1 && !l2) || (!l1 && l2))
                return false;
            if ((r1 && !r2) || (!r1 && r2))
                return false;
            if (l1)
                s1.push(l1);
            if (r1)
                s1.push(r1);
            if (l2)
                s2.push(l2);
            if (r2)
                s2.push(r2);
        }
        return true;
    }
};
// @lc code=end
