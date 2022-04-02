/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
// code3 费马平方和定理 math
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (int base = 2; base * base <= c; base++)
        // 非因子，枚举下一个
        {
            if (c % base != 0)
                continue;
            // 计算base的幂
            int exp = 0;
            while (c % base == 0)
            {
                c /= base;
                exp++;
            }
            // 根据Sum of two squares theorem判断
            if (base % 4 == 3 && exp % 2 != 0)
                return false;
        }
        /*
        例如11这样的test case，由于上面的for循环里base * base <= c, base == 11的时候不会进入循环
        因此在退出循环以后还需要再做一次判断
        */
        return c % 4 != 3;
    }
};
// @lc code=end
