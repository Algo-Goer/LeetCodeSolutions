/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
// code3 递归&回溯 枚举每个位置
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> ans;

    // 自定义函数
    void dfs(int pos, vector<bool> &vis, vector<int> &nums)
    {
        if (pos == nums.size())
        {
            res.push_back(ans);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (vis[i])
                continue;
            vis[i] = true;
            ans.push_back(nums[i]);
            dfs(pos + 1, vis, nums);
            ans.pop_back(); // backtrack
            vis[i] = false; // backtrack
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        // 枚举每一个位置，看看有哪些数字可以选择
        if (nums.size() <= 0)
            return res;

        vector<bool> vis(nums.size(), false);

        dfs(0, vis, nums);
        return res;
    }
};
// @lc code=end
