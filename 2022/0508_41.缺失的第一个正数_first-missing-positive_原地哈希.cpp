/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
// 原地哈希，类似[645]、[442]、[448]、剑指Offer03
/*
本题是Hard的原因：数字范围不一定是0~n-1或1~n的，相当于更普适了，特殊变一般
*/
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) // 类似[645]、[442]、[448]、剑指Offer03的情况
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1; // 说明数组中没有缺失的数字
    }
};
// @lc code=end
