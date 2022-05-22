/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
// DFS写法二
class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int x, int y)
    {
        if (!inArea(grid, x, y) || grid[x][y] == 0 || grid[x][y] == 2)
            return 0;

        grid[x][y] = 2;

        return 1 + dfs(grid, x - 1, y) + dfs(grid, x + 1, y) + dfs(grid, x, y - 1) + dfs(grid, x, y + 1);
    }

    bool inArea(vector<vector<int>> &grid, int x, int y)
    {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size(); 
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1) // 加上
                {
                    int tmp = dfs(grid, i, j);
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

