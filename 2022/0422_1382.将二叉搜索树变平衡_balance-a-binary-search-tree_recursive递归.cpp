/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
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

// code 递归

// 中序遍历把二叉搜索树变为有序数组，然后根据有序数组构建二叉平衡搜索树

class Solution
{
public:
    // Inorder Traversal -> ordered array
    void inorder(TreeNode *root, vector<int> &nums)
    {
        if (!root)
            return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    // build balanced BST from ordered array
    TreeNode *buildBST(vector<int> &nums, int start, int end) // 类似[108]将有序数组转换为二叉搜索树
    {
        if (start > end)
            return nullptr; // 如果数组为空，则不构建新结点
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nums[mid]);    // 创建新结点
        root->left = buildBST(nums, start, mid - 1); // 递归构建左子树
        root->right = buildBST(nums, mid + 1, end);  // 递归构建右子树
        return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> nums;
        inorder(root, nums);
        return buildBST(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
