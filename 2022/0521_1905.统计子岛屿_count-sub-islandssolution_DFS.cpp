/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 *
 * [1905] 统计子岛屿
 */

// @lc code=start
// DFS 在grid2中搜索某个岛屿时，判断是否在grid1出现过，如果全部出现，计数加1
class Solution
{
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool flag;

    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int x, int y)
    {
        if (x < 0 || x >= grid2.size() || y < 0 || y >= grid2[0].size() || grid2[x][y] == 0 || grid2[x][y] == 2)
        {
            return;
        }
        grid2[x][y] = 2; // visited

        if (grid1[x][y] == 0)
        {
            flag = false; // 只要这块岛屿里有一个格子在grid1中不是1，那么整块岛屿就没用了，不计入子岛屿
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            dfs(grid1, grid2, nx, ny);
        }
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int res = 0;
        for (int i = 0; i < grid2.size(); ++i)
        {
            for (int j = 0; j < grid2[0].size(); ++j)
            {
                if (grid2[i][j] == 1)
                {
                    flag = true;
                    dfs(grid1, grid2, i, j);
                    if (flag)
                        res++;
                }
            }
        }

        return res;
    }
};
// @lc code=end

