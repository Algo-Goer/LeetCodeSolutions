/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
// 前缀和O(n)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int res = nums[0];
        int cur = nums[0];
        for (int i = 1; i < n; ++i)
        {
            cur = max(nums[i], cur + nums[i]); // 前缀和
            res = max(res, cur);
        }
        return res;
    }
};
// @lc code=end
