/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
// code2 BFS 层序遍历
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 || !root2)
        {
            return root1 == NULL ? root2 : root1;
        }
        queue<TreeNode *> q;
        q.push(root1);
        q.push(root2);
        while (!q.empty())
        {
            TreeNode *node1 = q.front();
            q.pop();
            TreeNode *node2 = q.front();
            q.pop();
            node1->val += node2->val;
            if (node1->left && node2->left)
            {
                q.push(node1->left);
                q.push(node2->left);
            }
            else if (!node1->left)
            {
                node1->left = node2->left;
            }
            if (node1->right && node2->right)
            {
                q.push(node1->right);
                q.push(node2->right);
            }
            else if (!node1->right)
            {
                node1->right = node2->right;
            }
        }
        return root1;
    }
};
// @lc code=end
