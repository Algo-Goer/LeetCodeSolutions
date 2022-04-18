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

// code1 像[102]那样用BFS写出代码

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i)
            {
                Node *node = q.front();
                q.pop();
                tmp.push_back(node->val);
                for (auto child : node->children)
                {
                    q.push(child);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
// @lc code=end
