/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
// 计算1的个数 类[191]
// code4 DP
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; ++i)
        {
            if (i % 2 == 0)
                dp[i] = dp[i / 2];
            else if (i % 2 == 1)
                dp[i] = dp[i / 2] + 1;
        }
        return dp;
    }
};
// @lc code=end
