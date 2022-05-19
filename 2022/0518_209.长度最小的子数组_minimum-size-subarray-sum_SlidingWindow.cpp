/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
// Sliding Window & Two Pointers 类同[3]无重复字符的最长子串
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0) return 0;
        int ans = INT_MAX;
        int l = 0, r = 0;
        int sum = 0;
        while (r < n)
        {
            sum += nums[r];
            while (sum >= target)
            {
                ans = min(ans, r - l + 1);
                sum -= nums[l++]; 
                /*
                也可以写成
                sum -= nums[l];
                ++l;
                */
            }
            ++r;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end
