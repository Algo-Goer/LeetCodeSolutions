/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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

/*
code1 DFS/递归
先对原二叉树通过递归进行中序遍历，将所有结点值存入list中，以list中的第一个元素作为根结点
再遍历list中剩下的其他元素作为树的右子结点
最后返回新树
*/

class Solution
{
public:
    TreeNode *inorder(TreeNode *root, vector<int> &list)
    {
        if (!root)
            return nullptr;
        inorder(root->left, list);
        list.push_back(root->val);
        inorder(root->right, list);
        return root;
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        vector<int> v;
        inorder(root, v);
        TreeNode *newRoot = new TreeNode(v[0]); // 创建新树的根结点
        TreeNode *cur = newRoot;
        for (int i = 1; i < v.size(); ++i)
        {
            cur->right = new TreeNode(v[i]); // 将剩下元素作为右子结点
            cur = cur->right;
        }
        return newRoot; // 返回新树
    }
};
// @lc code=end
