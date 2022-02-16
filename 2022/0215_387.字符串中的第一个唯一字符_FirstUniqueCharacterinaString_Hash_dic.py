#
# @lc app=leetcode.cn id=387 lang=python3
#
# [387] 字符串中的第一个唯一字符
#

# @lc code=start
# 哈希表：找出频次为1的第一个字符
class Solution:
    def firstUniqChar(self, s: str) -> int:
        dic = {}
        for i in s:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1
        for i in s:
            if dic[i] == 1:
                return s.index(i)
        return -1
# @lc code=end

