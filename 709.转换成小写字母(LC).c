/*
 * @lc app=leetcode.cn id=709 lang=c
 *
 * [709] 转换成小写字母
 */

// @lc code=start

char *toLowerCase(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isupper(s[i]))
        {
            s[i] += 32;
        }
    }
    return s;
}
// @lc code=end
