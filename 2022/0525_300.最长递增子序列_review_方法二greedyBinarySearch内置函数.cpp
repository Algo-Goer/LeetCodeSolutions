/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
// Greedy & Binary Search内置函数lower_bound()
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return 0;
        vector<int> LIS; // 错误：vector<int> LIS(n);
        LIS.push_back(nums[0]);
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > LIS[LIS.size() - 1])
                LIS.push_back(nums[i]);
            else
            {
                auto pos = lower_bound(LIS.begin(), LIS.end(), nums[i]); // 下标
                *pos = nums[i];
            }
        }
        return LIS.size();
    }
};
// @lc code=end

