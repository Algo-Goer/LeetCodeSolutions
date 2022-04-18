/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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

/*
层序遍历
队列实现：遍历从根结点开始，首先将根结点入队，然后开始执行循环：结点出队、访问该结点、其左右孩子入队

层序基本过程：
先根结点入队，然后
1. 从队列中取出一个元素
2. 访问该元素所指结点
3. 若该元素所指结点的左右孩子结点非空，则将其左右孩子的指针顺序入队

void LevelOrderTraversal(BinTree BT)
{
    Queue Q; BinTree T;
    if (!BT) return; // 若是空树直接返回
    Q = CreatQueue(MaxSize); // 创建并初始化队列Q
    AddQ(Q, BT); // 将根结点入队
    while (!IsEmpty(Q))
    {
        T = DeleteQ(Q); // 出队
        printf("%d\n", T->Data); // 访问取出队列的结点
        if (T->Left) AddQ(Q, T-Left);
        if (T->Right) AddQ(Q, T-Right);
    }
}
*/

// code1 Queue/BFS

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> tmp;
            int curSize = q.size(); // 每一层结点个数
            for (int i = 0; i < curSize; ++i)
            {
                TreeNode *cur = q.front(); // 访问队首元素
                q.pop();
                tmp.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            res.push_back(tmp); 
        }
        return res;
    }
};
// @lc code=end
