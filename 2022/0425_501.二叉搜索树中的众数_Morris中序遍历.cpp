/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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

// code2 Morris中序遍历

class Solution
{
public:
    int base, count, maxCount; // 为了不用哈希节省空间而设置
    // base记录当前数字，count记录当前数字重复次数，maxCount维护已经扫描过的数中出现最多的那个数字的出现次数
    // 二叉搜索树的中序遍历这里是非严格单调递增，注意含等号
    vector<int> res;

    void update(int x) // 自定义函数
    {
        if (x == base)
            ++count;
        else
        {
            count = 1;
            base = x;
        }
        if (count == maxCount)
            res.push_back(base);
        if (count > maxCount)
        {
            maxCount = count;
            res.clear();
            res.push_back(base);
        }
    }

    vector<int> findMode(TreeNode *root)
    {
        // Morris中序遍历
        TreeNode *cur = root, *pre = NULL;
        while (cur)
        {
            if (!cur->left) // 无左子树
            {
                update(cur->val);
                cur = cur->right;
                continue;
            }
            pre = cur->left;                        // 有左子树
            while (pre->right && pre->right != cur) // 有左子树，找到cur左子树上最右节点
            {
                pre = pre->right;
            }
            if (!pre->right) // 如果mostRight的right指针指向NULL，让其指向cur，cur向左移动，开始遍历左子树
            {
                pre->right = cur;
                cur = cur->left;
            }
            else // 如果mostRight的right指针指向cur，说明左子树已经遍历过，让right指针指向NULL，cur向右移动，开始遍历右子树
            {
                pre->right = NULL;
                update(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
// @lc code=end
