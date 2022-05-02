/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
// code2 Morris遍历
/*
Morris遍历的一个重要步骤是寻找当前节点的前驱节点
1. 如果cur无左孩子，cur向右移动cur=cur->right
2. 如果cur有左孩子，找到cur左子树上最右节点，记为mostRight
2.1 如果mostRight的right指针指向NULL，让其指向cur，cur左移，开始遍历左子树cur=cur->left
2.2 如果mostRight的right指针指向cur，让其指向NULL，cur右移，说明左子树已经遍历完，开始遍历右子树cur=cur->right
*/
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left)
            {
                // 如果cur有左子树，找到cur左子树上最右节点，记为mostRight
                TreeNode *mostRight = cur->left;
                while (mostRight->right)
                    mostRight = mostRight->right; // 一直走到最右节点
                mostRight->right = cur->right;    // 将cur的右子树挂到mostRight的右子树上
                cur->right = cur->left;           // 将cur的左子树挂到cur的右子树上
                cur->left = NULL;                 // 将cur的左子树指针置空
            }
            cur = cur->right; // 向右移动cur
        }
    }
};
// @lc code=end
