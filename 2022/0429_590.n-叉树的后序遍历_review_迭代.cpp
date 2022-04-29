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
// code3 非递归/迭代/显式栈 写法二
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
            Node *node = s.top();
            s.pop();
            res.push_back(node->val);
            for (int i = 0; i < node->children.size(); ++i)
            {
                s.push(node->children[i]); // 左右入栈，一会出栈并加入ans时是右左
            }
        }
        // res 根右左 
        reverse(res.begin(), res.end()); // 左右根
        return res;
    }
};
// @lc code=end
