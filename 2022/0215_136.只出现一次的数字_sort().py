#
# @lc app=leetcode.cn id=136 lang=python3
#
# [136] 只出现一次的数字
#

'''
给定一个非空整数数组
除了某个元素只出现一次以外
其余每个元素均出现两次
找出那个只出现了一次的元素。

你的算法应该具有线性时间复杂度
你可以不使用额外空间来实现吗
'''
# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return 2 * sum(set(nums)) - sum(nums)   # set集合去重
# @lc code=end

