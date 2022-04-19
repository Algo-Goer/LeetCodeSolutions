/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

// code1 递归
/*
在前序遍历中找到根结点值，根结点为前序遍历的第一个元素值
在中序遍历中根据根结点值找到根结点位置，从而找到中序遍历里的左右子树，并求出左右子树结点个数
通过递归不断划分左右子树
*/

class Solution
{
public:
    unordered_map<int, int> index;
    TreeNode *build(const vector<int> &preorder, const vector<int> &inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
    {
        if (preorder_left > preorder_right || inorder_left > inorder_right) // 区间里没有元素
            return nullptr;
        // 前序遍历中的第一个结点就是根结点
        int preorder_root = preorder_left;
        // 在中序遍历中定位根结点
        int inorder_root = index[preorder[preorder_root]]; // 哈希找到相对应值的位置

        // 建立根结点
        TreeNode *root = new TreeNode(preorder[preorder_root]);
        // 左子树中的结点数
        int left_size = inorder_root - inorder_left;
        // 递归构造左子树，并连接到根结点
        // 先序遍历中，从preleft+1开始，前left_size个数就对应了中序遍历中的前left_size个元素
        root->left = build(preorder, inorder, preorder_left + 1, preorder_left + left_size, inorder_left, inorder_root - 1);
        // 递归构造右子树，并连接到根结点
        // 先序遍历中，从preleft+left_size+1开始到preorder_right的元素就对应了中序遍历中从inorder_root+1到inorder_right的元素
        root->right = build(preorder, inorder, preorder_left + left_size + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        // 已知前序中序序列都无重复元素，构造哈希映射，帮助快速定位根结点
        for (int i = 0; i < n; ++i)
        {
            index[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
// @lc code=end
