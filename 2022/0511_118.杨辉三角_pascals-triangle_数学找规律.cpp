/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
// code1 数学 找规律
// 类似[120]三角形最小路径和
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res(numRows);
        res[0] = {1}; // 第一行输出[1]
        // or res[0].push_back(1);
        for (int i = 1; i < numRows; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (j == 0 || j == i)
                    res[i].push_back(1);
                else
                {
                    res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]); // 正上方的数字+正上方左边的数字
                }
            }
        }
        return res;
    }
};
// @lc code=end
