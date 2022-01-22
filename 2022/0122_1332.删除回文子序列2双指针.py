#
# @lc app=leetcode.cn id=1332 lang=python3
#
# [1332] 删除回文子序列
#

# @lc code=start
"""
双指针
"""
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        left, right = 0, len(s) - 1
        ans = 0
        while left < right:
            if s[left] != s[right]:
                ans = 2
                break  # 跳出while循环
            left += 1
            right -= 1
        else:
            ans = 1
        return ans

        
        
         
# @lc code=end

