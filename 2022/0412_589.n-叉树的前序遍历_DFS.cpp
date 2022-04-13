/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// code3 DFS递归
class Solution
{
public:
    vector<int> ans;

    void dfs(Node *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i)
        {
            dfs(root->children[i], ans);
        }
    }

    vector<int> preorder(Node *root)
    {
        if (root == nullptr)
            return {};
        dfs(root, ans);
        return ans;
    }
};
// @lc code=end
