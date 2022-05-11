/*
 * @lc app=leetcode.cn id=865 lang=cpp
 *
 * [865] 具有所有最深节点的最小子树
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
// code3 不需要反复计算深度，一次DFS遍历
class Solution
{
private:
    int maxDepth = INT_MIN;
    TreeNode *res;
    int Depth(TreeNode *root, int depth)
    {
        if (!root)
            return depth;
        int leftD = Depth(root->left, depth + 1);
        int rightD = Depth(root->right, depth + 1);
        int curMax = max(leftD, rightD);
        maxDepth = max(maxDepth, curMax);
        if (leftD == maxDepth && rightD == maxDepth)
            res = root;
        return curMax; // 找到左右子树深度都为最大值的节点记录下来
    }

public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        Depth(root, 0);
        return res;
    }
};
// @lc code=end
