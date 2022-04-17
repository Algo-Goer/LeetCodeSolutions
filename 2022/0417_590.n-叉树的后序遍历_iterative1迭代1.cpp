/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
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

// code2 非递归/迭代/显式栈 仿照前序遍历但是写的是根右左，然后逆序即左右根

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;
        stack<Node *> s;
        s.push(root);
        while (!s.empty())
        {
            auto cur = s.top();
            s.pop();
            res.push_back(cur->val);
            for (auto child : cur->children)
                s.push(child);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
