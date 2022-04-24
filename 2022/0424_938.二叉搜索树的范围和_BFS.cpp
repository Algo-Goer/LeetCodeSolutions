/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
// code2 BFS
class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum = 0;
        queue<TreeNode *> q({root}); // q({root})不可以写成q，否则出现WA
        /*
        Finished
        Your Input
        [10,5,15,3,7,null,18]
        7
        15
        Output (0 ms)
        0
        Expected Answer
        32
        */
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (node == NULL)
                continue; // 每次取出队首结点时，如果结点为空则跳过该结点
            if (node->val > high)
                q.push(node->left);
            else if (node->val < low)
                q.push(node->right);
            else
            {
                sum += node->val;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return sum;
    }
};
// @lc code=end
