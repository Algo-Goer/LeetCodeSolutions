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
// code2 DFS&递归 没有哈希表优化时间复杂度
class Solution
{
public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        if (!root) return root;
        // 获取当前节点的左右子树的最大深度
        int leftD = FindDepth(root->left);
        int rightD = FindDepth(root->right);
        // 如果两边深度相同，则当前根节点即要找到的最近公共祖先
        if (leftD == rightD) return root;
        // 如果不相等，就去深度大的子树那边继续DFS寻找
        if (leftD > rightD) return subtreeWithAllDeepest(root->left);
        else return subtreeWithAllDeepest(root->right);
    }
    int FindDepth(TreeNode *root)
    {
        if (!root) return 0;
        return max(FindDepth(root->left), FindDepth(root->right)) + 1;
    }
};
// @lc code=end
