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

// code2 Morris traversal 空间复杂度O(1) 写法一

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
    void recoverTree(TreeNode *root)
    {
        TreeNode *x = nullptr, *y = nullptr, *pre = nullptr, *mostRight = nullptr;
        while (root)
        {
            // 如果有左子树，就递归遍历左子树
            if (root->left)
            {
                mostRight = root->left;
                // 找出左子树最右边的叶子节点
                while (mostRight->right && mostRight->right != root)
                {
                    mostRight = mostRight->right;
                }
                /*
                如果左子树最右边的叶子节点的右孩子为NULL，说明根节点是第一次访问到的
                那么就把它的右孩子指向根节点，再递归遍历左子树
                */
                if (mostRight->right == nullptr)
                {
                    mostRight->right = root;
                    root = root->left;
                }
                else
                {
                    /*
                    否则说明根节点是第二次访问，那就说明左子树已经递归完毕
                    那么就判断一下是否存在逆序对
                    记得把左子树最右叶子节点的右孩子改空指针
                    然后递归遍历右子树
                    */
                    if (pre && pre->val > root->val)
                    {
                        if (x == nullptr)
                            x = pre;
                        y = root;
                    }
                    mostRight->right = nullptr;
                    pre = root;
                    root = root->right;
                }
            }
            // 如果没有左子树，那就直接遍历右子树，同时判断是否存在逆序对
            else
            {
                if (pre && pre->val > root->val)
                {
                    if (x == nullptr)
                        x = pre;
                    y = root;
                }
                pre = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};
// @lc code=end
