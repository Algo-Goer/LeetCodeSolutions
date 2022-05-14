/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
// 二维动态规划，完成 剑指OfferII 095.最长公共子序列 而来
// code3 dp 状态压缩 空间复杂度为min(m, n)
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int m = grid.size();
        int n = grid[0].size();

        int more = max(m, n);
        int less = min(m, n);
        bool rowmore = more == m; // 行数是不是大于等于列数
        int dp[less];             // 辅助数组的长度取行列数最小值
        dp[0] = grid[0][0];
        for (int i = 1; i < less; ++i)
        {
            dp[i] = dp[i - 1] + (rowmore ? grid[0][i] : grid[i][0]);
        }
        for (int i = 1; i < more; ++i)
        {
            dp[0] = dp[0] + (rowmore ? grid[i][0] : grid[0][i]);
            for (int j = 1; j < less; ++j)
            {
                dp[j] = min(dp[j - 1], dp[j]) + (rowmore ? grid[i][j] : grid[j][i]);
            }
        }

        return dp[less - 1];
    }
};
// @lc code=end
