/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
// code2 BFS 层序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        string ret;

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node == nullptr)
                ret += "#,";
            else
            {
                ret += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        // 根据逗号把字符串数组分隔开，用指针连接关系
        vector<TreeNode *> nodes;
        for (int i = 0; i < data.size(); ++i)
        {
            int j = i;
            while (j < data.size() && data[j] != ',')
                j++;
            string str = data.substr(i, j - i);
            if (str == "#")
                nodes.push_back(nullptr);
            else
                nodes.push_back(new TreeNode(stoi(str)));
            i = j;
        }

        int i = 0, j = 1;
        while (j < nodes.size())
        {
            if (nodes[i] != nullptr)
            {
                nodes[i]->left = nodes[j];
                nodes[i]->right = nodes[j + 1];
                j += 2;
            }
            i += 1;
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
