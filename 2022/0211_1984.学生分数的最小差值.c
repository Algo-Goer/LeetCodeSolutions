/*
 * @lc app=leetcode.cn id=1984 lang=c
 *
 * [1984] 学生分数的最小差值
 */

// @lc code=start
// 双指针（左右指针）
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int minimumDifference(int* nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int min = INT_MAX;
    for (int i = 0; i < numsSize - k + 1; i++)
    {
        min = min < nums[i + k - 1] - nums[i] ? min : nums[i + k - 1] - nums[i];
    }
    return min;
}
// @lc code=end

