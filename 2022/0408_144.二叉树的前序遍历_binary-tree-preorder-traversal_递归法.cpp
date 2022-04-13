/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
递归
二叉树前序遍历：root->left->right
在访问左子树或右子树时，按同样方式遍历，直到遍历完整棵树
void PreOrderTraversal(BinTree BT) // 前序遍历
{
if (BT)
    {
        printf("%d ", BT->Data);
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->Right);
    }
}
*/
class Solution
{
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return ans;
        ans.push_back(root->val);       // 访问根结点
        preorderTraversal(root->left);  // 递归调用左子树
        preorderTraversal(root->right); // 递归调用右子树
        return ans;
    }
};
// @lc code=end
