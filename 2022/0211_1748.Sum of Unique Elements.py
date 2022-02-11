#
# @lc app=leetcode.cn id=1748 lang=python3
#
# [1748] 唯一元素的和
#

# @lc code=start
# 状态机，只需遍历一次，时间复杂度为O(n)
# 首次访问一个元素时，将该元素加入答案，并将元素状态标记为1
# 在访问到一个标记为1的元素时，说明这个元素至少第二次出现，所以将其从答案中减去，并标记为2

class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        ans = 0
        state = {}
        for num in nums:
            if num not in state:
                ans += num
                state[num] = 1
            elif state[num] == 1:
                ans -= num
                state[num] = 2
        return ans
# @lc code=end

