/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
// BFS
class Solution
{
public:
    // 同[200]岛屿数量
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    void bfs(vector<vector<int>> &grid, int x, int y)
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        grid[x][y] = 0;
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1)
                {
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                }
            }
        }    
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1) // 如果是边界，就可以作为起点进行DFS
                {
                    if (grid[i][j] == 1)
                        bfs(grid, i, j);
                }
            }
        }

        // 再次遍历，统计飞地数量
        int res = 0;
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
