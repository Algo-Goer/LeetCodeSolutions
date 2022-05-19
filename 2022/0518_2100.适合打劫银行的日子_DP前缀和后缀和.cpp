/*
 * @lc app=leetcode.cn id=2100 lang=cpp
 *
 * [2100] 适合打劫银行的日子
 */

// @lc code=start
// DP 写法2 
class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        int n = security.size();
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 1; i < n; ++i)
        {
            if (security[i] <= security[i - 1])
                left[i] = left[i - 1] + 1; // prefix sum
        }
        // 后缀和
        for (int i = n - 2; i >= 0; --i)
        {
            if (security[i] <= security[i + 1])
                right[i] = right[i + 1] + 1;
        }

        vector<int> ans;
        for (int i = time; i < n - time; ++i)
        {
            if (left[i] >= time && right[i] >= time)
                ans.emplace_back(i);
        }
        return ans;
    }
};
// @lc code=end
