/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
// DP3
// 递推公式：LIS[i] = max(LIS[j]) + 1, 0<=j<i且nums[j]<nums[i]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;
        vector<int> LIS(n, 0); // 空间复杂度O(n)
        int res = 1;
        for (int i = 0; i < n; ++i)
        {
            LIS[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    LIS[i] = max(LIS[i], LIS[j] + 1); // 找一个最大的LIS[j]，把它加1并更新到LIS[i]
                    res = max(res, LIS[i]); // 储存最大值，有更大的LIS[i]就更新
                }
            }
        }
        return res;
    }
};
// @lc code=end

