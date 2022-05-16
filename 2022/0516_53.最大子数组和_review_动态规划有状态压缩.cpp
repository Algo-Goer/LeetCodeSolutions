/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
// classic DP 有状态压缩
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        int tmp = nums[0];
        int res = nums[0];

        for (int i = 1; i < n; ++i)
        {
            tmp = max(tmp + nums[i], nums[i]);
            res = max(res, tmp);
        }
        return res;
    }
};
// @lc code=end
