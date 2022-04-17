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

// code3 非递归/迭代/显式栈 写法二 双栈写法

/*
根右左 逆序 左右根
根右左从前序遍历根左右修改而来
可以选用两个栈，一个用于根右左遍历，一个用于保存序列，最后的代码和前序遍历只是稍作一些修改
*/

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> s1;
        TreeNode *p = root;
        // 记录前一个访问的结点，判断是否右子树访问过
        TreeNode *r = nullptr; // TreeNode *r;也可AC 
        while (!s1.empty() || p != nullptr)
        {
            if (p) // 先对左子树进行操作
            {
                s1.push(p);
                p = p->left;
            }
            else
            {
                p = s1.top();  // 查看栈顶结点
                if (p->right && p->right != r) // 若右子树存在且未被访问过
                {
                    p = p->right;
                    s1.push(p); // 没被访问过的右子树入栈
                    // 对右子树进行同样操作
                    p = p->left; 
                }
                else  // 右子树已经访问完毕，就要pop并访问了
                {
                    // 访问栈顶元素并访问
                    ans.push_back(p->val); // 相当于访问
                    s1.pop();
                    r = p;       // 记录最近访问过的结点
                    p = nullptr; // 结点访问完后重置p指针
                }
            }
        }
        return ans;
    }
};
// @lc code=end
