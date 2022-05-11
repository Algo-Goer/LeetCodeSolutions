/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
// code2 递归&回溯 枚举每个数字
class Solution
{
public:
    vector<vector<int>> res;

    // 自定义函数
    void dfs(int pos, vector<bool> &vis, vector<int> &nums, vector<int> &ans)
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
            ans[i] = nums[pos];
            dfs(pos + 1, vis, nums, ans);
            vis[i] = false; // backtrack
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        // 枚举每一个数字，看看有哪些位置可以选择
        if (nums.size() <= 0)
            return res;

        vector<bool> vis(nums.size(), false);
        vector<int> ans(nums.size(), 0);

        dfs(0, vis, nums, ans);
        return res;
    }
};
// @lc code=end
