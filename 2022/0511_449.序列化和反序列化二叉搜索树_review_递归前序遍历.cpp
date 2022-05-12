/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
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
// code2 参照负雪明烛
class Codec
{
public:
    // 自定义
    void preorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    // 自定义
    string vectorToString(vector<int> &val)
    {
        string res;
        if (val.empty())
            return res;
        for (int i = 0; i < val.size() - 1; ++i) // 最后一个数后面不用加","
        {
            res += to_string(val[i]) + ",";
        }
        res += to_string(val[val.size() - 1]); // 最后一个数单独加上
        return res;
    }

    // 自定义
    vector<int> split(string &str)
    {
        vector<int> res;
        size_t pos = 0; // size_t类型表示C中任何对象所能达到的最大长度，它是无符号整数
        string token;
        while ((pos = str.find(",")) != string::npos)
        /*
        string::npos参数 —— npos 是一个常数，用来表示不存在的位置
        例如，有两个字符串a、b，判断a字符串是否包含b字符串
        如果字符串不存在包含关系，那么返回值就一定是npos
        if(a.find(b)!=string::npos)
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
        */
        {
            token = str.substr(0, pos);
            res.push_back(stoi(token));
            str.erase(0, pos + 1);
        }
        res.push_back(stoi(str));
        return res;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        vector<int> val;
        preorder(root, val);
        return vectorToString(val);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return NULL;
        vector<int> val = split(data);
        TreeNode *root = new TreeNode(val[0]); // 创建根节点
        vector<int> left, right;
        for (int v : val)
        {
            if (v < val[0])
            {
                left.push_back(v); // 根据BST的性质
            }
            else if (v > val[0])
            {
                right.push_back(v); // 根
            }
        }
        root->left = deserialize(vectorToString(left));   // 递归创建左子树 左
        root->right = deserialize(vectorToString(right)); // 递归创建右子树 右  根左右 前序遍历反序列化
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
