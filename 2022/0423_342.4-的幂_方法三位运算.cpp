/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start

// code3 位运算

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
        // (n & 0xaaaaaaaa) == 0表示n的二进制表示中，有且只有一个1，而且这个1是在奇数位上
    }
};
// @lc code=end
