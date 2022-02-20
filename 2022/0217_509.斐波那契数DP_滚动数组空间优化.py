#
# @lc app=leetcode.cn id=509 lang=python3
#
# [509] 斐波那契数
#

# @lc code=start
'''
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. 
That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

动态规划:DP table
'''

'''
动态规划特点:
1、重叠子问题
2、状态转移方程(the most critical)
3、最优子结构
题型:求最值(最优化算法)
核心:穷举

解题思路:
1、明确状态
2、明确选择
3、明确dp函数/数组的定义
4、明确base case
'''
# 动态规划
# 状态转移方程：f(n) = f(n-1) + f(n-2)
class Solution:
    def fib(self, n: int) -> int:
        if n < 2:  
            return n
        a, b = 0, 1
        for i in range(2, n + 1):
            a, b = b, a + b # 滚动数组，空间复杂度O(1)
        return b



# @lc code=end

