/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 */

// @lc code=start

/*
 * 比纯粹二分搜索[704]多了一步按顺序插入没有的值
 * 时间复杂度：O(logn)，其中n为数组的长度
 * 空间复杂度：O(1)。我们只需要常数空间存放若干变量，本题中mid记录中间值
 */
int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1; // right指向最后一个元素的索引

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // 等价于left + (right - left) / 2，但有效防止了 left 和 right 太大直接相加导致溢出
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1; // [mid + 1, right]
        else if (nums[mid] > target)
            right = mid - 1; // [left, mid - 1]
    }
    return left; // 纯二分搜索[704]是返回return -1，这里要按顺序插入，所以返回left索引位置
}
// @lc code=end

