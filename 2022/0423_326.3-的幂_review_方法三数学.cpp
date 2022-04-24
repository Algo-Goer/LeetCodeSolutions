/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start

// code3 数学
/*
在题目给定的32位有符号整数的范围内，最大的3的幂为3^19=1162261467
判断n是否是3^19约数即可
*/
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        return n > 0 && 1162261467 % n == 0;
    }
};
// @lc code=end
