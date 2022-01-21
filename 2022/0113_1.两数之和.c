/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/*
 * Note: The returned array must be malloced, assume caller calls free().
 * 暴力枚举法，时间复杂度O(n^2)
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int * index = malloc(sizeof(int) * 2);
                index[0] = i; index[1] = j;
                *returnSize = 2;
                return index;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
// @lc code=end

