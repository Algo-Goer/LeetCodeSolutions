/*
 * @lc app=leetcode.cn id=509 lang=c
 *
 * [509] 斐波那契数
 */

// @lc code=start

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int a = 0, b = 0, c = 1;
    for (int i = 2; i <= n; i++)
    {
        a = b;
        b = c;
        c = a + b;
    }
    return c;
}
// @lc code=end
