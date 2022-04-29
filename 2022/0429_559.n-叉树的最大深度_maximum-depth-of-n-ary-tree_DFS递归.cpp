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
// 基础题[104]二叉树的最大深度 [111]二叉树的最小深度
// code1 DFS postorder N叉树最大深度 = maxChildDepth + 1

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int maxChildDepth = 0;
        for (auto child : root->children)
        {
            int depth = maxDepth(child);
            if (depth > maxChildDepth)
                maxChildDepth = depth;
        }
        return maxChildDepth + 1;
    }
};
// @lc code=end
