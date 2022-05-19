/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
// code3 Binary Search & PrefixSum
// 用C++内置函数accumulate()、prefixSumtial_sum()、lower_bound()
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int sumall = accumulate(nums.begin(), nums.end(), 0);
        if (!n || sumall < target) return 0; // 排除数组为空或者所有数字加和都小于target的情况
        vector<int> prefixSum(n + 1, 0); // 第一个为哑节点，这样后续有i-1时就不用特别处理第一个元素了
        partial_sum(nums.begin(), nums.end(), prefixSum.begin() + 1);
        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i)
        {
            int newTarget = prefixSum[i - 1] + target;
            auto it = lower_bound(prefixSum.begin(), prefixSum.end(), newTarget); // 正整数数组，肯定升序，所以用lower_bound()查找第一个大于等于newTarget的元素
            if (it != prefixSum.end())
            {
                ans = min(ans, (int)(it - prefixSum.begin() - i + 1)); // it - prefixSum.begin()为查找的j的下标
            }
        }
        return ans;
    }
};
// @lc code=end
