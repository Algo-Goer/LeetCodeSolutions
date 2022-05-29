/*
 * @lc app=leetcode.cn id=2176 lang=cpp
 *
 * [2176] 统计数组中相等且可以被整除的数对
 */

// @lc code=start
// 枚举
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[i] == nums[j] && (i * j) % k == 0)
                    res++;
            }
        }
        return res;
    }
};
// @lc code=end

