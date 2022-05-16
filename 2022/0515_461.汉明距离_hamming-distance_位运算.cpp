/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
// 求两个整数异或结果中1的个数 类[338]
// code2 位运算
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int s = x ^ y, res = 0;
        while (s)
        {
            res += s & 1;
            s >>= 1;
        }
        return res;
    }
};
// @lc code=end
