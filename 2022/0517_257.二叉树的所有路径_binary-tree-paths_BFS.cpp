/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// BFS 层序遍历
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> paths;
        if (root == NULL)
            return paths;
        queue<TreeNode *> node_queue;
        queue<string> path_queue;

        node_queue.push(root);
        path_queue.push(to_string(root->val));

        while (!node_queue.empty())
        {
            TreeNode* node = node_queue.front();
            string path = path_queue.front();
            node_queue.pop();
            path_queue.pop();

            if (node->left == NULL && node->right == NULL) 
            {
                paths.push_back(path);
            }
            else
            {
                if (node->left)
                {
                    node_queue.push(node->left);
                    path_queue.push(path + "->" + to_string(node->left->val));
                }
                if (node->right)
                {
                    node_queue.push(node->right);
                    path_queue.push(path + "->" + to_string(node->right->val));
                }
            }
        }
        return paths;
    }
};
// @lc code=end
