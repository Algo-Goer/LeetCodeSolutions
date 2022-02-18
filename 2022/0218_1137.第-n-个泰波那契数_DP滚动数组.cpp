/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
/*
泰波那契序列Tn定义如下
T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0的条件下 Tn+3 = Tn + Tn+1 + Tn+2
给你整数n
请返回第 n 个泰波那契数Tn 的值。
0 <= n <= 37
*/

/**
 * DP动态规划
 * 空间优化：滚动数组 
 */
class Solution {
public:
    int tribonacci(int n) 
    {
        if(n == 0) return 0;
        if(n <= 2) return 1;
        int p = 0, q = 1, r = 1;
        for (int i = 3; i <= n; ++i)
        {
            int temp = p + q + r;
            p = q;
            q = r;
            r = temp;
        }
        return r;   
    }
};
// @lc code=end

