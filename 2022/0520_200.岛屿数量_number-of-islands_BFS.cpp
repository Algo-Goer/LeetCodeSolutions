// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem200.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
// BFS 同[733]图像渲染
class Solution
{
public:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    void bfs(vector<vector<char>> &grid, int x, int y)
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        grid[x][y] = '2'; // visited 同[733]图像渲染
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1')
                {
                    q.push({nx, ny});
                    grid[nx][ny] = '2';
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = (int)grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    bfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
// @lc code=end
