#
# @lc app=leetcode.cn id=300 lang=python3
#
# [300] 最长递增子序列
#

# @lc code=start
'''
给你一个整数数组nums
找到其中最长严格递增子序列的长度
子序列是由数组派生而来的序列
删除(或不删除)数组中的元素而不改变其余元素的顺序
例如[3,6,2,7]是数组[0,3,1,6,2,2,7] 的子序列

动态规划
'''

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)  # len = len(nums)Runtime Error:UnboundLocalError: local variable 'len' referenced before assignment
        if len == 0:
            return 0
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
        
# @lc code=end

