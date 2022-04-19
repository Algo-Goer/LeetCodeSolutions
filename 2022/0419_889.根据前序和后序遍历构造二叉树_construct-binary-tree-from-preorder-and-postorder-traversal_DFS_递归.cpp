/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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

// DFS/递归

class Solution
{
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        if (preorder.size() == 0 || postorder.size() == 0)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        if (preorder.size() == 1)
            return root; // 由于下面要用preorder[1]，因此必须判断其个数
        auto it = find(postorder.begin(), postorder.end(), preorder[1]);
        int len = it - postorder.begin() + 1; // 左子树长度
        vector<int> preleft(preorder.begin() + 1, preorder.begin() + 1 + len);
        vector<int> preright(preorder.begin() + 1 + len, preorder.end());
        vector<int> postleft(postorder.begin(), postorder.begin() + len);
        vector<int> postright(postorder.begin() + len, postorder.end() - 1);

        root->left = constructFromPrePost(preleft, postleft);
        root->right = constructFromPrePost(preright, postright);
        return root;
    }
};
// @lc code=end
