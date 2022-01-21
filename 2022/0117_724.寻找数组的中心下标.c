/*
 * @lc app=leetcode.cn id=724 lang=c
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start

/*
 * 遍历到第i个元素时，左侧元素之和为sumOfPart。
 * 如果左侧元素之和=右侧元素之和，那么2 * sumOfPart + nums[i] == 数组元素之和sum
 */

/*
 * 时间复杂度：O(n)，n为数组的长度
 * 空间复杂度：O(1)
 */
int pivotIndex(int *nums, int numsSize)
{
    int sum = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        sum += nums[i]; // 数组中所有数之和
    }
    int sumOfPart = 0; // 遍历到第i个元素时，其左侧元素之和为sumOfPart
    for (int i = 0; i < numsSize; ++i)
    {
        if (2 * sumOfPart + nums[i] == sum)
        {
            return i;
        }
        sumOfPart += nums[i];
    }
    return -1;
}
// @lc code=end
