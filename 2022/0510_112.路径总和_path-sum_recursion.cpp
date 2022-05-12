/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
// code1 Recursive DFS 递减思路
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL) // 递归结束
            return false;
        /*
        若当前节点的左子树和右子树均为空，则表示当前的节点为叶子节点
        此时，若当前节点值等于targetSum，则表示存在符合条件的路径使得根节点到当前叶子节点的数值之和等于targetSum
        */
        if (root->left == NULL && root->right == NULL && root->val == targetSum)
            return true;
        /*
        判断以当前节点左节点为根的子树是否存在
        根节点到叶子节点的路径之和为taregtSum-当前节点值
        */
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
// @lc code=end
