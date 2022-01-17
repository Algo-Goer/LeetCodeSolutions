/*
 * @lc app=leetcode.cn id=1991 lang=c
 *
 * [1991] 找到数组的中间位置
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
int findMiddleIndex(int *nums, int numsSize)
{
    int sum = 0; // 数组所有元素之和
    for (int i = 0; i < numsSize; ++i)
    {
        sum += nums[i];
    }
    int sumOfPart = 0; // 遍历到第i个元素时，其左侧元素之和
    for (int i = 0; i < numsSize; i++) // ++i也可，对于for循环都一样
    {
        if (sumOfPart * 2 + nums[i] == sum)
            return i;
        sumOfPart += nums[i];
    }
    return -1;
}

// @lc code=end
