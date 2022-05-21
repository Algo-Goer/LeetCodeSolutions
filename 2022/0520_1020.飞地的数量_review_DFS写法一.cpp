/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
// DFS写法一
class Solution
{
public:
    // 辅助函数
    void dfs(vector<vector<int>> &grid, int x, int y)
    {
        grid[x][y] = 0; // 陆地被边上海水淹没，从'1'变为'0'，不计入飞地
        if (inArea(grid, x - 1, y))
            dfs(grid, x - 1, y);
        if (inArea(grid, x + 1, y))
            dfs(grid, x + 1, y);
        if (inArea(grid, x, y - 1))
            dfs(grid, x, y - 1);
        if (inArea(grid, x, y + 1))
            dfs(grid, x, y + 1);
    }

    // 辅助函数
    bool inArea(vector<vector<int>> &grid, int x, int y)
    {
        int m = grid.size();
        int n = grid[0].size();
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1;
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1) // 如果是边界，就可以作为起点进行DFS
                {
                    if (grid[i][j] == 1)
                        dfs(grid, i, j);
                }
            }
        }
        // 再次遍历，统计飞地数量
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                    res++;
            }
        }
        return res;
    }
};
// @lc code=end
