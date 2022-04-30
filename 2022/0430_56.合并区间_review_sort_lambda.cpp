/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
// sort & lambda
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i)
        {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L)
                merged.push_back({L, R});
            else
                merged.back()[1] = max(merged.back()[1], R);
        }
        return merged;
    }
};
// @lc code=end

// code2 原地合并后排序

class Solution
{
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n)
    {
         for (int i = 0; i < n; ++i)
         {
             A[m + i] = B[i];
         }
         sort(A.begin(), A.end());
    }
};