/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start

// code2 递归

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        if (n % 3 != 0)
            return false;
        return isPowerOfThree(n / 3); // 递归，分解为结构相同规模更小的子问题
    }
};
// @lc code=end
