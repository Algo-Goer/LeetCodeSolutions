/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
// DFS
class Solution {
private:
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int row, col;
public:
    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y] != 0)
            return ;
        grid[x][y] = 1; // 把土地变为海水  // 如果是2也可以AC
        for (int i = 0; i < 4; ++i)
        {
            dfs(grid, x + dx[i], y + dy[i]); // 淹没上下左右的未封闭的土地
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        for (int i = 0; i < row; ++i) 
        {
            dfs(grid, i, 0); // 以左边界的土地作为被淹没的起点
            dfs(grid, i, col - 1); // 以右边界的土地作为被淹没的起点
        }
        for (int j = 0; j < col; ++j)
        {
            dfs(grid, 0, j); // 以上边界的土地作为被淹没的起点
            dfs(grid, row - 1, j); // 以下边界的土地作为被淹没的起点
        }
        
        int res = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 0)
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
