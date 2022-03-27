/*
 * @lc app=leetcode.cn id=2022 lang=cpp
 *
 * [2022] 将一维数组转变成二维数组
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        vector<vector<int>> ans;
        if (original.size() != m * n)
            return ans; // 如果无法构成这样的二维数组，返回一个空的二维数组
        for (auto it = original.begin(); it != original.end(); it += n)
        {
            // ans.push_back(vector<int>(it, it + n)); 不能漏vector<int>
            ans.emplace_back(it, it + n);  // 不用写vector<int>
        }
        return ans;
    }
};
// @lc code=end
