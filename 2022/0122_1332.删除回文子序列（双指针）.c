/*
 * @lc app=leetcode.cn id=1332 lang=c
 *
 * [1332] 删除回文子序列
 */

// @lc code=start

/* 
相同字符组成的子序列一定是回文子序列(双指针)
先判断是否是回文序列（类第9题回文数）
是的话，返回1；反之就返回2
*/
int removePalindromeSub(char *s)
{
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right)
    {
        if (s[left] != s[right])
            return 2;
        left++;
        right--;
    }
    return 1;
}
// @lc code=end
