/*
 * @lc app=leetcode.cn id=747 lang=c
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start

/* 
 * 跟昨日题目类似，昨天找到尽可能小的两个值，今天找到尽可能大的两个值
 * 找出最大值和次大值，并判断最大是否是次大值的至少2倍
 */

int dominantIndex(int *nums, int numsSize)
{
    if (numsSize == 1)
        return 0;         // 如果只有一个数字，题目中满足条件，所以返回下标0
    int max = nums[0];    // 如果题目中没有说明所有int都大于等于0
    int second = INT_MIN; // 如果题目中没有说明所有int都大于等于0
    int index = 0;        // 用index储存最大值的下标
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > max)
        {
            second = max;  // 原来最大值更新为次大值
            max = nums[i]; // 更新最大值
            index = i;     // 更新最大值下标
        }
        else if (nums[i] > second) // 但小于max
        {
            second = nums[i]; // 更新次大值
        }
    }
    return (max >= (2 * second)) ? index : -1;
}
// 下面代码是第三种AC代码
// int dominantIndex(int *nums, int numsSize)
// {
//     if (numsSize == 1)
//         return 0;      // 如果只有一个数字，题目中满足条件，所以返回下标0
//     int max = INT_MIN;   // 如果题目中没有说明所有int都大于等于0
//     int second = INT_MIN;  // 如果题目中没有说明所有int都大于等于0
//     int index = 0; // 用index储存最大值的下标
//     for (int i = 0; i < numsSize; i++)
//     {
//         if (nums[i] > max)
//         {
//             second = max;  // 原来最大值更新为次大值
//             max = nums[i]; // 更新最大值
//             index = i;     // 更新最大值下标
//         }
//         else if (nums[i] > second) // 但小于max
//         {
//             second = nums[i]; // 更新次大值
//         }
//     }
//     return (max >= (2 * second)) ? index : -1;
// }
// @lc code=end
