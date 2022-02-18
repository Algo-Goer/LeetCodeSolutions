/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
/**
 * 编写一个函数
 * 输入是一个无符号整数
 * 以二进制串的形式
 * 返回其二进制表达式中数字位数为 '1' 的个数
 * 也被称为汉明重量
 */

// 位运算
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int res = 0;
        while (n)  // 只有n不为0就循环
        {
            res += n & 1;    // n&1表示n的最后一位
            n >>= 1;         // n>>1表示n的最后一位右移一位
        }
        return res;
    }
};
// @lc code=end

