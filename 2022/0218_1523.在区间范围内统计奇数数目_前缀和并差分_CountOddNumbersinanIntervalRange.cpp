/*
 * @lc app=leetcode.cn id=1523 lang=cpp
 *
 * [1523] 在区间范围内统计奇数数目
 */

// @lc code=start
/**
 * 给你两个非负整数 low 和 high 
 * 请你返回 low 和 high 之间（包括二者）奇数的数目
 * Given two non-negative integers low and high. 
 * Return the count of odd numbers between low and high (inclusive).
 */

/**
 * 1、计算0到high之间奇数的个数
 * 2、计算0到low-1之间奇数个数
 * 3、两者作差
 * 求奇数个数公式：(x+1)/2
 * 
 */
class Solution {
public:
    int countOdds(int low, int high) 
    {
        int a1 = (low - 1 + 1) / 2;
        int a2 = (high + 1) / 2;
        return a2 - a1;
    }
};
// @lc code=end

