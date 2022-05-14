/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
// 二维动态规划，完成 剑指OfferII 095.最长公共子序列 而来
// code2 原地dp不占用额外空间 没有状态压缩
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 1; i < m; ++i)
        {
            grid[i][0] += grid[i - 1][0]; // 纵向填充第一列
        }
        for (int j = 1; j < n; ++j)
        {
            grid[0][j] += grid[0][j - 1]; // 横向填充第一行
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};
// @lc code=end
