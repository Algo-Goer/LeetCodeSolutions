/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
// code1 DFS 先序遍历 写法一
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // 同[449]
    string serialize(TreeNode* root) 
    {
        if (root == NULL)
            return "#";
        return to_string(root->val) + " " + serialize(root->left) + " " +serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<string> array{""};
        for (auto& ch : data)
        {
            if (ch == ' ')
                array.push_back("");
            else
                array.back().push_back(ch);
        }
        int i = 0;
        return dfs(array, i);
    }

    // 自定义函数dfs/递归 同[449]
    TreeNode *dfs(vector<string>& strs, int &i)
    {
        string str = strs[i];
        ++i;
        if (str == "#")
            return NULL;
        TreeNode *node = new TreeNode(stoi(str));
        node->left = dfs(strs, i);
        node->right = dfs(strs, i);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

