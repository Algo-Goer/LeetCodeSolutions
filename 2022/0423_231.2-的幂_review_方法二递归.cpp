/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start

// code2 递归
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        if (n % 2 != 0)
            return false;
        return isPowerOfTwo(n / 2);
    }
};
// @lc code=end
