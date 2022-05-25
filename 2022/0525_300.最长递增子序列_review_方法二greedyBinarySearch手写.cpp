/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
// Greedy & Binary Search手写
class Solution {
public:
    int binarySearch(vector<int>& nums, int target) // 相当于是lower_bound()，类[209]
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l; // 返回下标
    }
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
                int pos = binarySearch(LIS, nums[i]); // 下标
                if (LIS[pos] >= nums[i])  // 不写也可以AC，还是判断一下比较好，在[209]中就是必须判断的
                    LIS[pos] = nums[i]; // 替换
            }
        }
        return LIS.size();
    }
};
// @lc code=end

