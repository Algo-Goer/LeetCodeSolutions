/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
// 迭代
class Solution
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    cnt = 0; 
                    for (int k = 0; k < 4; ++k)
                    {
                        int nx = i + dx[k], ny = j + dy[k];
                        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == 0)
                            ++cnt;
                    }
                    ans += cnt;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
