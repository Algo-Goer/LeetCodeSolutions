/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
// 先序遍历非递归算法
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // 定义栈指针st
        stack<TreeNode *> st;
        TreeNode *p = root;
        vector<int> res;
        // 初始化栈st
        if (root != nullptr)
        {
            st.push(root);      // 将根结点压入栈
            while (!st.empty()) // 非空栈时循环
            {
                // 退出栈结点p并访问它
                p = st.top();
                st.pop();
                res.push_back(p->val);    // 将根结点压入结果集
                if (p->right != nullptr) // 有右孩子时将其进栈
                    st.push(p->right);
                if (p->left != nullptr) // 有左孩子时将其进栈
                    st.push(p->left);
            }
        }
        return res;
    }
};
// @lc code=end
