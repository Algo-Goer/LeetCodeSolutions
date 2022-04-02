/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
// code4 sqrt()找出b math
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (long a = 0; a * a <= c; ++a)
        {
            double b = sqrt(c - a * a);
            if (b == (int)b)
                return true;
        }
        return false;
    }
};
// @lc code=end
