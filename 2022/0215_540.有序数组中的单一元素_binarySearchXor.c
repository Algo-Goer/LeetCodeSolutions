/*
 * @lc app=leetcode.cn id=540 lang=c
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start

/**
 * 二分查找+异或
 */
// 1 <= nums.length <= 10^5
int singleNonDuplicate(int* nums, int numsSize)
{
    int left = 0, right = numsSize - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == nums[mid ^ 1])
            left = mid + 1;
        else
            right = mid;
    }
    return nums[left];
}
// @lc code=end

