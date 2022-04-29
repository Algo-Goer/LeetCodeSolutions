/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
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

// code2 BFS/迭代

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int depth = 0;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                Node *node = q.front();
                q.pop();
                for (auto child : node->children)
                {
                    q.push(child);
                }
            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end
