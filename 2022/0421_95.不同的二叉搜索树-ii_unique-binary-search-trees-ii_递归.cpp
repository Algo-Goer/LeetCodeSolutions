/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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

// code1 DFS/递归

/*
枚举根结点的位置来依次生成BST
1. 对于根结点值i，其左子树包含[1, i-1]，右子树包含[i+1, n]的不同方案
2. 拼接左右子树的不同方案
*/
class Solution
{
public:
    vector<TreeNode *> helper(int start, int end)
    {
        vector<TreeNode *> res;
        if (start > end)
        {
            res.push_back(nullptr);
        }
        for (int i = start; i <= end; ++i)
        {
            vector<TreeNode *> left = helper(start, i - 1);
            vector<TreeNode *> right = helper(i + 1, end);
            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> res;
        if (n == 0)
            return res;
        res = helper(1, n);
        return res;
    }
};
// @lc code=end
