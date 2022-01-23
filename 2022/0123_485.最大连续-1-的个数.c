/*
 * @lc app=leetcode.cn id=485 lang=c
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start

/*
用一个temp记录当前值，用一个his记录历史最大值，用max不断比较temp和his并更新最大值
遍历时遇到1，temp+1，遇到0temp归零
C中MAX(a,b)作为宏定义实现，这样不区分数据类型
*/

#define MAX(a,b) a > b ? a : b // 无分号
int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int temp = 0;
    int his = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] == 0)
            temp = 0;
        else
            temp++;
        his = MAX(his, temp);
    }
    return his;
}
// @lc code=end
