#
# @lc app=leetcode.cn id=540 lang=python3
#
# [540] 有序数组中的单一元素
#

# @lc code=start
# 快慢指针法，不过时间复杂度为O(n)不符合O(logn)的题目要求
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        slow = 0
        fast = 1
        while fast < len(nums):
            if nums[slow] != nums[fast]:
                return nums[slow]
            slow += 2
            fast += 2
        return nums[slow]
# @lc code=end

