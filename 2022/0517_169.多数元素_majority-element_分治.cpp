/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
// code4 分治
class Solution
{
public:
    // 自定义
    int getCount(vector<int> &nums, int num, int left, int right)
    {
        int count = 0;
        for (int i = left; i <= right; ++i)
        {
            if (nums[i] == num)
                count++;
        }
        return count;
    }

    // 自定义
    int getMode(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return nums[left];
        int mid = left + (right - left) / 2;
        int leftMode = getMode(nums, left, mid);
        int rightMode = getMode(nums, mid + 1, right);

        if (leftMode == rightMode)
            return leftMode;
        
        // 如果左右部分众数不等
        int leftCount = getCount(nums, leftMode, left, right);
        int rightCount = getCount(nums, rightMode, left, right);

        return rightCount > leftCount ? rightMode : leftMode;
    }

    int majorityElement(vector<int> &nums)
    {
        return getMode(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
