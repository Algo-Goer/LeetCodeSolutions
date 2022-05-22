/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
// DFS
class Solution {
public:
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int dfs(vector<vector<int>>& grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) 
            return 1; // 如果到边界或者为海水就返回1
        if (grid[x][y] == 2) // 如果是岛屿且访问过，就返回0
            return 0;
        grid[x][y] = 2; // visited
        int cnt = 0;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            cnt += dfs(grid, nx, ny);
        } 
        return cnt;
    }
   
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                    ans += dfs(grid, i, j);
            }
        }
        return ans;
    }
};
// @lc code=end

