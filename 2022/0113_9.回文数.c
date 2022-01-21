/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start

// 双指针
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    else if (x == 0)
        return true;
    else
    {
        char ar[100];         // 空间
        sprintf(ar, "%d", x); // 整数转化为字符串数组
        int left = 0;
        int right = strlen(ar) - 1;
        while (left < right)
        {
            if (ar[left] != ar[right])
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
}
// @lc code=end
