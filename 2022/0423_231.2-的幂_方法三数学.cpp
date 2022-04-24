/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start

// code3 数学
/*
在题目给定的32位有符号整数的范围内，最大的2的幂为2^30=1073741824
判断n是否是2^30约数即可
*/

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && 1073741824 % n == 0;
    }
};
// @lc code=end
