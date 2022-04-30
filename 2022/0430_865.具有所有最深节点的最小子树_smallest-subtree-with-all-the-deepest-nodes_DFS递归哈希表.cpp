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

// code1 DFS&递归&哈希表
class Solution
{
public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        FindDepth(root);
        return dfs(root);    
    }
private:
    unordered_map<TreeNode *, int> m; // 存储各个节点为根的树的高度
    TreeNode *dfs(TreeNode *root)
    {
        if (m[root] == 1) return root;
        else if (m[root->left] == m[root->right]) // 左右子树高度相等，返回根节点
            return root;
        else if (m[root->left] > m[root->right])  // 左子树高，则在左子树中求解
            return dfs(root->left);
        else // 右子树高则在右子树中求解
            return dfs(root->right);
    }
    int FindDepth(TreeNode *root) // 求出各个节点为根的树的高度
    {
        if (!root) return 0;
        int leftD = FindDepth(root->left);
        int rightD = FindDepth(root->right);
        int depth = max(leftD, rightD) + 1;
        m.insert({root, depth}); // 存入哈希表
        return depth;
    }
};
// @lc code=end
