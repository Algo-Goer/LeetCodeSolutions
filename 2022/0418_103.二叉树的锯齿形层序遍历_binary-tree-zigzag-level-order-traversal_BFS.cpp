// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem103.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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

// code1 先像[102]那样写BFS代码进行层序遍历，然后对ans中的奇数下标进行逆序

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            ans.push_back(tmp);
        }
        // 对ans中的奇数下标进行逆序
        for (int i = 1; i < ans.size(); i += 2)
        {
            reverse(ans[i].begin(), ans[i].end()); // 时间复杂度为O(n)，空间复杂度为O(1)
        }
        return ans;
    }
};
// @lc code=end
