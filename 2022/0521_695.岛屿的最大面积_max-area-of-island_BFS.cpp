/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
// BFS
class Solution
{
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int bfs(vector<vector<int>> &grid, int x, int y) // bfs矩阵遍历模板，[1020]、[200]都一模一样
    {
        /* 这段如果不写，下面主函数就必须写if (grid[i][j] == 1)，否则就输出为7（WA）而不是6了
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
            return 0;
        */
        queue<pair<int, int>> q;
        q.push({x, y});
        grid[x][y] = 2; // visited 改成0也可以AC
        int cnt = 1; // 在改标记后计数就顺便加1了，不要忘记计数
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 2; // visited 改成0也可以AC
                    ++cnt;
                    q.push({nx, ny});
                }
            }
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
                if (grid[i][j] == 1) // 要加上，否则输出为7（WA)，而不是6，虽然不知道为什么，因为DFS没有这句判断可以AC
                    ans = max(ans, bfs(grid, i, j));
            }
        }
        return ans;
    }
};
// @lc code=end
