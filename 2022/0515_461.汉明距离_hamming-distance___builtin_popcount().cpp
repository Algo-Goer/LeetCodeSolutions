/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
// 求两个整数异或结果中1的个数 类[338]
// code1 内置位计数函数
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        return __builtin_popcount(x ^ y); // __builtin_popcount()表示求x和y的异或结果中1的个数
    }
};
// @lc code=end
