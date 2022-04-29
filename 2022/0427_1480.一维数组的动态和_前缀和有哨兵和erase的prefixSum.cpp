/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
// code2 prefixSum 写法一
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        // 删除第一个元素
        prefixSum.erase(prefixSum.begin()); // erase()时间复杂度O(n)
        return prefixSum;
    }
};
// @lc code=end
