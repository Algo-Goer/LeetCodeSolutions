/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
/**
 * 给你一个整数n
 * 请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差
 */
class Solution {
public:
    int subtractProductAndSum(int n) 
    {
        int sum = 0;
        int product = 1;
        while (n)
        {
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }
        return product - sum;
    }
};
// @lc code=end

