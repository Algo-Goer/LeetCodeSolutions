/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// code4 DFS
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "#";
        string leftNode = serialize(root->left);
        string rightNode = serialize(root->right);
        return to_string(root->val) + "," + leftNode + "," + rightNode;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        list<string> list = split(data, ','); // 将字符串分隔成list
        TreeNode *res = buildTree(list);
        return res;
    }

    // 自定义
    TreeNode *buildTree(list<string> &list)
    {
        string val = list.front();
        list.pop_front(); // pop_front()表示删除list中的第一个元素
        if (val == "#")
            return NULL;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = buildTree(list);
        root->right = buildTree(list);
        return root;
    }
    // 自定义
    list<string> split(string str, char c)
    {
        list<string> res;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == c)
                continue;
            int j = i + 1;
            while (j < str.size() && str[j] != c)
                j++;
            res.push_back(str.substr(i, j - i));
            i = j;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
