/*
 * @lc app=leetcode.cn id=334 lang=c
 *
 * [334] 递增的三元子序列
 */

// @lc code=start

/*
* 双指针，分别记录最小值和第二小值。第三个变量如果存在，就返回true，反之false
* 没有要求连续数字，递增即可
* 要求O(n)的时间复杂度和O(1)的空间复杂度
*/

/*
#include <stdbool.h>  // bool类型函数定义
#include <limits.h>  // INT_MAX头文件
*/
bool increasingTriplet(int *nums, int numsSize)
{
    if (numsSize < 3)
        return false;
    int first = INT_MAX;  //  int first = nums[0];也可以的 
    int second = INT_MAX;
    for (int i = 0; i < numsSize; i++)  
    {
        if (nums[i] > second)
            return true;
        else if (nums[i] > first)
            second = nums[i];
        else
            first = nums[i];
    }
    return false;  // 找不到符合条件的nums[i]就返回false
}
// @lc code=end
