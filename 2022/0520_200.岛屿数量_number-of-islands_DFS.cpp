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
// DFS四个方向写法一
class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        // 主函数dfs前有一句判断，只有grid[x][y] == 1才会进入这个dfs
        grid[x][y] = '2'; // 标记visited
        if (inArea(grid, x - 1, y))
            dfs(grid, x - 1, y);
        if (inArea(grid, x + 1, y))
            dfs(grid, x + 1, y);
        if (inArea(grid, x, y - 1))
            dfs(grid, x, y - 1);
        if (inArea(grid, x, y + 1))
            dfs(grid, x, y + 1);
    }

    // 判断是否在网格中
    bool inArea(vector<vector<char>> &grid, int x, int y)
    {
        int m = grid.size();
        int n = grid[0].size();
        return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1';
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                // 如果是岛屿，才以它为起点开始DFS，遍历后，1变为2，表示visited，防止重复遍历
                if (grid[i][j] == '1')
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
// @lc code=end
