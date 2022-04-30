/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
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
4.30刚好刷了：
合并区间
合并有序数组
合并有序链表
合并二叉树
5.1的每日一题竟然是合并二叉搜索树
*/
class Solution
{
public:
    // 自定义inorder traversal函数
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        // 升序排列，二叉搜索树，inorder
        vector<int> res;
        inorder(root1, res);
        inorder(root2, res);
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
