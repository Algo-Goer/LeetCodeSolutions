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
// code2 迭代
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<Node *> stk; // 定义栈指针
        stk.push(root);
        Node *p = root;
        while (!stk.empty())
        {
            p = stk.top(); // 取栈顶元素
            stk.pop();
            ans.push_back(p->val);
            for (int i = p->children.size() - 1; i >= 0; --i)
            {
                stk.push(p->children[i]); // 将子节点压入栈，倒序，后进先出
            }
        }
        return ans;
    }
};
// @lc code=end
