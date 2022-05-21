/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
// DFS四个方向写法一
class Solution
{
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int dfs(vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
            return 0;

        grid[x][y] = 0;

        int cnt = 1;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            cnt += dfs(grid, nx, ny); // 这是跟[200]、[733]、[1020]的区别，这些题直接dfs，而且可以返回void类型
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1) // 加上
                    ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};
// @lc code=end
