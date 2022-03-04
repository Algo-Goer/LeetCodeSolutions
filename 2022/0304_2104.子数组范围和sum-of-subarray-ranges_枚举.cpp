/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 *
 * [2104] 子数组范围和
 */

// @lc code=start
/*
枚举法
首先枚举子数组的左边界i
然后枚举子数组的右边界j,且i<=j
在枚举j的过程中迭代计算子数组[i,j]的最小值minValue和最大值maxValue
然后将maxValue和minValue的差值不断加到结果集

nums长度区间[1,1000]
nums中元素区间[-10^9,10^9]
*/
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int minValue = nums[i];
            int maxValue = nums[i];
            for (int j = i; j < n; ++j)
            {
                minValue = min(minValue, nums[j]);
                maxValue = max(maxValue, nums[j]);
                res += maxValue - minValue;
            }
        }
        return res;
    }
};
// @lc code=end
