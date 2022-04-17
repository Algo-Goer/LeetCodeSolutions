/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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

// code4 非递归/迭代/显式栈 写法三
/*
前序遍历是根左右，后序遍历是左右根
我们根据前序遍历根右左，然后逆转下就是左右根
*/

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        while (root || st.size())
        {
            while (root)
            {
                st.push(root);
                ans.push_back(root->val); // 存放根
                root = root->right;       // 向右转
            }
            if (st.size())
            {
                auto t = st.top(); // 取出根
                st.pop();
                if (t->left)
                    root = t->left; // 向左转
            }
        }
        reverse(ans.begin(), ans.end()); // 逆转，把根右左变为左右根
        return ans;
    }
};
// @lc code=end
