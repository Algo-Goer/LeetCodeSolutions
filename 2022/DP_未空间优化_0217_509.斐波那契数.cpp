/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
/**
 * 动态规划DP Table
 * 状态转移方程f(n) = f(n-1) + f(n-2)
 * 设定一个数组进行存储，空间复杂度O(n)
 */
class Solution {
public:
    int fib(int n) 
    {
        if (n <= 1) return n; // 不写这句话会出现heap-buffer-overflow on address
        // 堆溢出,一般情况下是数组越界访问或者数组的下标错误造成的
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// @lc code=end

