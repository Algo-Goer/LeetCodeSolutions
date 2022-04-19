/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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

// DFS/递归 同[105]一样思路

class Solution
{
public:
    unordered_map<int, int> pos;
    TreeNode *dfs(vector<int> &inorder, vector<int> &postorder, int il, int ir, int pl, int pr)
    {
        if (il > ir || pl > pr)
            return nullptr;
        int postorder_root = postorder[pr];
        int inorder_root = pos[postorder[pr]];
        TreeNode *root = new TreeNode(postorder[pr]);
        int left_size = inorder_root - il;
        root->left = dfs(inorder, postorder, il, inorder_root - 1, pl, pl + left_size - 1);
        root->right = dfs(inorder, postorder, inorder_root + 1, ir, pl + left_size, pr - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; ++i)
        {
            pos[inorder[i]] = i; // 哈希记录中序遍历的根结点位置
        }
        return dfs(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};
// @lc code=end
