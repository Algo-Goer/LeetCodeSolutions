#
# @lc app=leetcode.cn id=1137 lang=python3
#
# [1137] 第 N 个泰波那契数
#

# @lc code=start
'''
泰波那契序列Tn定义如下
T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0的条件下 Tn+3 = Tn + Tn+1 + Tn+2
给你整数n
请返回第 n 个泰波那契数Tn 的值。
0 <= n <= 37
'''

'''
动态规划
'''
class Solution:
    def tribonacci(self, n: int) -> int:
        # 不写下面这语句会出现Runtime Error--IndexError: list assignment index out of range
        if n <= 1:
            return n
        
        dp = [None] * (n + 1)  
        dp[0] = 0
        dp[1] = 1
        dp[2] = 1
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
        return dp[n]
        
# @lc code=end

