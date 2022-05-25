/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
// classic DP2 空间状态压缩从二维到一维
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m < n)
            return uniquePaths(n, m);
        vector<int> dp(n);
        for (int i = 0; i < n; ++i)
        {
            dp[i] = 1;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];        
    }
};
// @lc code=end
