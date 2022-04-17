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

// code1 递归

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;
        for (auto child : root->children)
        {
            auto tmp = postorder(child);
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        res.push_back(root->val);
        return res;
    }
};
// @lc code=end
