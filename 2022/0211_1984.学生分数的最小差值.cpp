/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 *
 * [1984] 学生分数的最小差值
 */

// @lc code=start
// 排序sort()、滑动窗口
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i <= n - k; ++i)
        {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;      
    }
};
// @lc code=end

