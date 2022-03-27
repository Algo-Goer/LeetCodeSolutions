/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
/*
矩阵基本功：
1、主副对角线元素位置，题目LeetCode_1572_矩阵对角线元素的和 Easy
2、二维数组的一维表示，想到做过的一道题目LeetCode_2022_将一维数组转变成二维数组 Easy
*/
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c)
            return mat;
        vector<vector<int>> ans(r, vector<int>(c)); // 初始化矩阵
        for (int i = 0; i < m * n; ++i)
        {
            ans[i / c][i % c] = mat[i / n][i % n];
        }
        return ans;
    }
};
// @lc code=end
