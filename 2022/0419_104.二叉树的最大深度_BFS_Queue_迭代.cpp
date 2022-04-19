/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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

// code2 BFS/Queue/Iterative

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int depth = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *p = q.front();
                q.pop();
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            ++depth;
        }
        return depth;
    }
};
// @lc code=end
