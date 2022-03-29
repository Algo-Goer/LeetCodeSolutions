/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */

// @lc code=start
// 数组、矩阵
class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int n = accounts.size();
        int m = accounts[0].size();
        vector<int> wealth(n, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                wealth[i] +=  accounts[i][j];
            }
        }
        sort(wealth.begin(), wealth.end());
        return wealth[n - 1];
    }
};
// @lc code=end
