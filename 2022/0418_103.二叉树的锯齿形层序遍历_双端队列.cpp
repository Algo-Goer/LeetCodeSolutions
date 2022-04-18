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

// code3 双端队列BFS

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        deque<TreeNode *> dq;
        dq.push_back(root);
        bool flag = true;
        while (!dq.empty())
        {
            vector<int> tmp;
            int size = dq.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node;
                if (flag)
                {
                    node = dq.front();
                    dq.pop_front();
                    if (node->left)
                        dq.push_back(node->left);
                    if (node->right)
                        dq.push_back(node->right);
                }
                else
                {
                    node = dq.back();
                    dq.pop_back();
                    if (node->right)
                        dq.push_front(node->right);
                    if (node->left)
                        dq.push_front(node->left);
                }
                tmp.push_back(node->val);
            }
            flag = !flag;
            ans.push_back(tmp);
        }
        return ans;
    }
};
// @lc code=end
