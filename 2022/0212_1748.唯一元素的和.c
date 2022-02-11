/*
 * @lc app=leetcode.cn id=1748 lang=c
 *
 * [1748] 唯一元素的和
 */

// @lc code=start

/**
 * 分配排序中的桶排序，相当于用数组代替哈希表
 * 桶排序算法原理：创建一个新数组，把数分到有限数量的桶内，每个桶里的数据再排序
 * 当每个桶的数据范围为1且数据都是整数时，桶排序的时间复杂度在所有情况下都为O(n)，因为它是一个线性排序算法。但很有可能浪费很多空间
 */

/**
 * 如果写成100，会出现越界错误
 * runtime error: index 100 out of bounds for type 'int [100]'  
 */
int sumOfUnique(int* nums, int numsSize)
{
    int freq[101] = {0};        // 因为题目中1 <= nums.length <= 100，数量不大，所以可以分配101个桶
    for (int i = 0; i < numsSize; ++i)
    {
        freq[nums[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < 101; ++i)
    {
        if (freq[i] == 1)
        {
            ans += i;
        }
    }
    return ans;
}
// @lc code=end

