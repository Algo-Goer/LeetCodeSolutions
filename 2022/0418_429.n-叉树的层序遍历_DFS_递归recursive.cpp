/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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

// code2 像[102]那样写出DFS/递归前序遍历代码

class Solution
{
public:
    void dfs(Node *root, int level, vector<vector<int>> &ans)
    {
        if (!root)
            return;
        while (ans.size() <= level)
        {
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);
        for (auto child : root->children)
        {
            dfs(child, level + 1, ans);
        }
    }
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
};
// @lc code=end
