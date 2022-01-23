#
# @lc app=leetcode.cn id=485 lang=python3
#
# [485] 最大连续 1 的个数
#

# @lc code=start

# 用一个temp记录当前值，用一个his记录历史最大值，用max不断比较temp和his并更新最大值
# 遍历时遇到1，temp+1，遇到0temp归零
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        his, temp = 0, 0
        for i in nums:
            if i == 0:
                temp = 0
            else:
                temp += 1
            his = max(his ,temp)
        return his

# @lc code=end

