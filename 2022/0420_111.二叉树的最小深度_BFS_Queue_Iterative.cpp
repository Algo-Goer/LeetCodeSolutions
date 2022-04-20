/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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

// code3 BFS/Queue/Iterative

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            level++;
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                // 如果当前结点的左右子树均为null，直接返回level
                if (!node->left && !node->right)
                    return level;
                // 左右子结点，哪个非空，就加入到队列
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return level;
    }
};
// @lc code=end
