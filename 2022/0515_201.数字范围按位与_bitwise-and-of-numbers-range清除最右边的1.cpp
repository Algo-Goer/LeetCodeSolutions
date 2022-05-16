/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
// 从 第293场周赛第三题6065.按位与结果大于零的最长组合 而来
// code2 清楚二进制串中最右边的1
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        while (right > left)
        {
            right &= right - 1;
        }
        return right;
    }
};
// @lc code=end
