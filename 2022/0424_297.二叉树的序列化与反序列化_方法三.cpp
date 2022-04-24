/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
// code3 递归 先序遍历 写法二
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
1,(2,#,#,)(3,[4,#,#],[5,#,#])
DFS(1)
DFS(2)
DFS(3)
DFS(4)
DFS(5)
*/
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "#";
        else
            return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
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
        return DFS(nodes, 0);
    }

    TreeNode *DFS(vector<TreeNode *> &nodes, int cur)
    {
        if (nodes[cur] == NULL)
            return NULL;

        TreeNode *left = DFS(nodes, cur + 1); // 左子树的根结点
        int leftSize = getNum(left);
        TreeNode *right = DFS(nodes, cur + leftSize + 1); // 右子树的根结点
        nodes[cur]->left = left;
        nodes[cur]->right = right;
        return nodes[cur];
    }

    int getNum(TreeNode *node)
    {
        if (node == NULL)
            return 1;
        return 1 + getNum(node->left) + getNum(node->right);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
