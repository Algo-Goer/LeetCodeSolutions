#
# @lc app=leetcode.cn id=1189 lang=python3
#
# [1189] “气球” 的最大数量
#

# @lc code=start
'''
给你一个字符串text,你需要使用 text 中的字母来拼凑尽可能多的单词"balloon"
字符串text中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词"balloon"
'''
'''
哈希、计数
字母balloon需要2个l和o,可把字母l和o的数量分别除以2,返回min{各个字母数量}即可以构成单词的数量
'''
# 时间复杂度为O(n+C)，n为text.length，O(C)为求C个字母（本题C=5）出现频次的最小值;空间复杂度为O(C)
import collections  # LeetCode提交时可不写，这是VSCode自动生成的


class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        count = collections.Counter(text)
        return min(count['b'], count['a'], count['l'] // 2, count['o'] // 2, count['n'])

# @lc code=end

