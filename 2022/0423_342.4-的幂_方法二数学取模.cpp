/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start

// code2 数学 取模

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
        // return n > 0 && (n % 3 == 1); // 光这个不够，比如7
    }
};
// @lc code=end
