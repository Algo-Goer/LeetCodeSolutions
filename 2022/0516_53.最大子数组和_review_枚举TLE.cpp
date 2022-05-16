/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
// enumeration
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxV = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum += nums[j];
                if (sum > maxV)
                    maxV = sum;
            }
        }
        return maxV;
    }
};
// @lc code=end
