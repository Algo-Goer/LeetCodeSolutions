/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
// code4 递归&回溯 最详细解释，引自小猫咪吃python
class Solution
{
public:
    vector<vector<int>> res; // 存储所有排列方法
    vector<bool> st;         // state 存储每个数字是否遍历过
    vector<int> path;        // 存储当前排列方法

    // 使用递归实现回溯，其中u表示当前已经排列的个数
    // 自定义函数
    void dfs(int u, vector<int> &nums)
    {
        // 如果已经排列的数字个数已经和数组长度相等，说明已经完成一次排列
        // 把当前排列方法放入最终结果，并return
        if (u == nums.size()) // u 目前使用了几个数字 // 1      // 例如i = 0不满足条件，就跳到4  // 例如i = 1 不满足条件，跳到4
        {
            res.push_back(path); // path 保存当前路径，保存的是值，比如nums[0] // 2
            return;              // 3
        }
        // 枚举数字
        for (int i = 0; i < nums.size(); ++i) // 4 // 例如i = 0 // i = 0 // i = 1
        {
            // 没有使用过的数字参与排列
            if (!st[i]) // 5  // dfs(1): 0已经遍历过，不满足条件，跳回4
            {
                path.push_back(nums[i]); // 6  // 例如i = 0, path = [1]  // i = 1, path = [1, 2]
                st[i] = true;            // 7  // 例如i = 0, 下标为0的元素1访问过，标记true，st = [1, 0, 0] // st = [1, 1, 0]
                dfs(u + 1, nums);        // 8  // 例如i = 0, dfs(1, nums) //dfs(2, nums)
                st[i] = false;           // 9
                path.pop_back();         // 10
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            st.push_back(false);
        }
        dfs(0, nums); // dfs的第一个参数：目前使用了几个数字，目前处于树的第几层
        return res;   // 保存最终结果——所有路径
    }
};
// @lc code=end
