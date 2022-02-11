#
# @lc app=leetcode.cn id=1984 lang=python3
#
# [1984] 学生分数的最小差值
#

# @lc code=start
import re


class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        ans = float("inf")   # 无穷大，类似C++中的INT_MAX
        for i in range(n - k + 1):
            ans = min(ans, nums[i + k - 1] - nums[i])
        return ans

# @lc code=end

