/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
// code4 recursion without memorization
class Solution
{
public:
    int fib(int n)
    {
        int result;
        if (n < 2)
            result = n;
        else
            result = fib(n - 1) + fib(n - 2);
        return result;
    }
};
// @lc code=end
