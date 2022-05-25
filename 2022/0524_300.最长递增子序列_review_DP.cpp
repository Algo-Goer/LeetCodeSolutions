/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
// DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            LIS[i] = 1; // 初始化默认的长度

            for (int j = 0; j < i; ++j) // 前面最长的序列
            {
                if (nums[j] < nums[i] && LIS[j] + 1 > LIS[i])
                    LIS[i] = LIS[j] + 1;
            }
        }
        return *max_element(LIS.begin(), LIS.end());
    }
};
// @lc code=end

