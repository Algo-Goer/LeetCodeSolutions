/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
// 求两个整数异或结果中1的个数 类[338]
// code3 Brian Kernighan算法
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int s = x ^ y, res = 0;
        while (s)
        {
            s &= s - 1;
            res++;
        }
        return res;
    }
};
// @lc code=end
