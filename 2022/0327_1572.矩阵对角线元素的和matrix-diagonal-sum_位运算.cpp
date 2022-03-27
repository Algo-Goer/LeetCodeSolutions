/*
 * @lc app=leetcode.cn id=1572 lang=cpp
 *
 * [1572] 矩阵对角线元素的和
 */

// @lc code=start
// 对矩阵的题目还很生疏，要多练习
// 位运算&矩阵
class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int sum = 0;
        int mid = n / 2;
        for (int i = 0; i < n; ++i)
        {
            sum += mat[i][i] + mat[i][n - 1 - i];
        }
        return sum - mat[mid][mid] * (n & 1);
        /*
        mat[mid][mid] * (n & 1)
        矩阵边长是偶数时，n&1=0，不用减去中心元素
        矩阵边长是奇数时，n&1=1，需要减去中心元素
        */
    }
};
// @lc code=end
