/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution
{
public:
    int m;
    int n;
    // 定义dfs函数
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        // 不越界,就可以四个方式搜索
        // 创建一个二维数组
        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) // 如果不越界且没有被访问过
        {
            grid[i][j] = 0; // 一旦被搜索/访问,就相当于被海水淹没,为0
            dfs(i - 1, j, grid);
            dfs(i + 1, j, grid);
            dfs(i, j - 1, grid);
            dfs(i, j + 1, grid);
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int ans = 0;        // 初始化飞地数量
        m = grid.size();    // 行数
        n = grid[0].size(); // 列数
        // 深度优先搜索

        // 从边界开始遍历，边界都能被访问（为0）
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) // 如果是边界
                {
                    dfs(i, j, grid);
                }
            }
        }

        // 对于每一个点
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) // 如果还没有被访问过
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

// @lc code=end
