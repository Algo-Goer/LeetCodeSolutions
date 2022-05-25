/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
// DP
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> LIS(n);
        vector<int> count(n);
        int maxlen = 1;

        for (int i = 0; i < n; ++i)
        {
            LIS[i] = 1, count[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    if (LIS[j] + 1 > LIS[i])
                    {
                        LIS[i] = LIS[j] + 1;
                        count[i] = count[j];
                    }
                    else if (LIS[j] + 1 == LIS[i])
                        count[i] += count[j];
                }
            }
            maxlen = max(maxlen, LIS[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (LIS[i] == maxlen)
                ans += count[i];
        }

        return ans;
    }
};
// @lc code=end
