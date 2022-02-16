#
# @lc app=leetcode.cn id=540 lang=python3
#
# [540] 有序数组中的单一元素
#

# @lc code=start
# 异或运算：两数相同异或为0,0^a = a
# 时间复杂度O(n)不符合O(log n)题目要求
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            res ^= num
        return res
# @lc code=end

