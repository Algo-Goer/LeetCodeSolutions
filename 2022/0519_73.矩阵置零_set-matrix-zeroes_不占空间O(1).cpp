/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
// 空间O(1)
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool flag_row0 = false, flag_col0 = false;
        for (int i = 0; i < m; ++i)
        {
            if (!matrix[i][0]) // 或if (matrix[i][0] == 0)
                flag_col0 = true;
        }
        for (int j = 0; j < n; ++j)
        {
            if (matrix[0][j] == 0)
                flag_row0 = true;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (!matrix[i][j])
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (!matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;
            }
        }
        if (flag_col0 == true)
        {
            for (int i = 0; i < m; ++i)
            {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0)
        {
            for (int j = 0; j < n; ++j)
            {
                matrix[0][j] = 0;
            }
        }
    }
};
// @lc code=end
