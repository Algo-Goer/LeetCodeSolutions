/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
// code1 递归&回溯
class Solution
{
public:
    vector<vector<int>> res; // 全局变量

    vector<vector<int>> permute(vector<int> &nums)
    {
        dfs(nums, nums.size(), 0);
        return res;
    }

    // 辅助函数
    void dfs(vector<int> &nums, int n, int first)
    {
        if (first == n)
        {
            res.push_back(nums); // 递归结束
            return;
        }
        for (int i = first; i < n; ++i)
        {
            swap(nums[i], nums[first]);
            dfs(nums, n, first + 1);
            swap(nums[i], nums[first]);
        }
    }
};
// @lc code=end
