/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
// 从 第293场周赛第三题6065.按位与结果大于零的最长组合 而来
// 求left和right的二进制形式的公共前缀
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        if (left == 0) 
        return 0;
        int i = 0;
        while (left != right)
        {
            left >>= 1;  // 右移一位
            right >>= 1;
            ++i;  
        }
        return left << i; 
    }
};
// @lc code=end
