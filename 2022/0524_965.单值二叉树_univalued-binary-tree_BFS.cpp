/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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
// BFS
class Solution {
public:
    // 自定义
    bool bfs(TreeNode *root, int target)
    {
        if (!root) return true;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int curSize = q.size();
            for (int i = 0; i < curSize; ++i)
            {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->val != target) return false;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return true;
    }

    bool isUnivalTree(TreeNode* root) {
        int target = root->val;
        return bfs(root, target);        
    }
};
// @lc code=end

