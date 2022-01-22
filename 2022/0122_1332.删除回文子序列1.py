#
# @lc app=leetcode.cn id=1332 lang=python3
#
# [1332] 删除回文子序列
#

# @lc code=start
"""
相同字符组成的子序列一定是回文子序列
先判断是否是回文序列（类第9题回文数）
是的话，返回1；反之就返回2
"""


class Solution:
    def removePalindromeSub(self, s: str) -> int:
        return 1 if s == s[::-1] else 2
        """
        因为步长可以为负数，所以s[::-1]代表反转字符串，
        如果是s[:-1]就是删除最后一个字符后返回剩下字符
        """
        
        
         
# @lc code=end

