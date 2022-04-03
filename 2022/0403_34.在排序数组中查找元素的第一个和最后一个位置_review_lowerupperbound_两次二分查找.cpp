/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
// code4 两次二分查找 lower_bound() & upper_bound()
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // 遍历nums，看看有没有target
        for (auto &num : nums)
        {
            if (num == target)
            {
                // 用lower_bound()查找第一个大于等于8的元素，返回其下标
                int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
                // 用upper_bound()查找第一个大于8的元素，返回其下标
                int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
                return {first, last - 1};
            }
        }
        return {-1, -1};
    }
};
// @lc code=end
