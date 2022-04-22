/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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

// code1 中序遍历&递归 空间复杂度O(n)

/*
1 5 3 4 2 6
5 3 4 2逆序
prev->val > root->val  // 5 > 3
first = prev // 5
second = root // 2
swap first and second
*/

class Solution
{
public:
    TreeNode *prev;   // 前序指针prev指向前一个节点
    TreeNode *first;  // 第一个需要交换的节点
    TreeNode *second; // 第二个需要交换的节点
    // 中序遍历二叉树
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        if (prev && first == nullptr && prev->val > root->val) // 前序指针prev指向前一个节点，如果前一个节点存在，且第一个需要交换的结点为空，且前一个节点的值大于当前节点的值
            first = prev;                                      // 第一个需要交换的节点设置为前一个节点
        if (prev && first && prev->val > root->val)
            second = root; // 第二个需要交换的节点设置为当前节点
        prev = root;       // 前序指针prev指向当前节点
        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        swap(first->val, second->val);
    }
};
// @lc code=end
