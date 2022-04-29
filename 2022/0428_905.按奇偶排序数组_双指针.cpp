/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
// code3 双指针，一次遍历，原地交换
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0, j = n - 1; i < j;)
        {
            while (i < j && nums[i] % 2 == 0)
                ++i; // i遇到奇数停下右移脚步
            while (i < j && nums[j] % 2 != 0)
                --j;                // j遇到偶数停下左移脚步
            swap(nums[i], nums[j]); // 原地交换
        }
        return nums;
    }
};
// @lc code=end
