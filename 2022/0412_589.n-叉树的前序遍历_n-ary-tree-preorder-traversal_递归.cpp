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
// code1 递归
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        ans.push_back(root->val);
        for (auto child : root->children)
        {
            auto childAns = preorder(child); 
            ans.insert(ans.end(), childAns.begin(), childAns.end()); // 在指定位置ans.end()前插入childAns区间所有元素
        }
        return ans;
    }
};
// @lc code=end
