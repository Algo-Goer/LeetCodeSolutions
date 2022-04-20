/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// code1 递归

/*
BST特点就是左子树所有结点值都小于当前结点值，右子树的所有结点值都大于当前结点值，且每棵子树都具有这个特点
从根结点开始遍历
1. 如果两个结点值都小于根结点，说明它们都在根结点的左子树上，往左子树上找
2. 如果两个结点值都大于根结点，说明它们都在根结点的右子树上，往右子树上找
3. 如果一个结点值大于根结点，一个结点值小于根结点，说明它们一个在根结点的左子树上，一个在根结点的右子树上，那么根结点就是他们最近的公共祖先节点LCA(lowest common ancestor)
*/

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return nullptr;
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
// @lc code=end
