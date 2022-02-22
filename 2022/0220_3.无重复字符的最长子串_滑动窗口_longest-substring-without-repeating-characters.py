#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#

# @lc code=start

# 0 <= s.length <= 5 * 10^
# s由英文字母、数字、符号和空格组成
'''
这道题跟300.最长递增子序列(Medium)区别在于本题是子串,必须连着的数字
第300题数字可以不相连,用的是DP
本题用滑动窗口
'''
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)
        '''
        滑动窗口与字典:
        没有重复字母时,调整右边界
        窗口内出现重复字母时,调整左边界

        哈希表
        双指针
        '''
        dic, cnt, left = {}, 0, 0
        for right in range(len(s)):
            if s[right] in dic: # 若当前元素在字典中,则调整左边界
                # 左边界调整为重复字母的下一个位置
                left = max(left, dic[s[right]] + 1)
            # 把当前right指针指向的元素放入dic中
            dic[s[right]] = right # dic[s[right]]表示s[right]在s中的位置
            cnt = max(cnt, right - left + 1) # 更新最大长度
        return cnt


        


# @lc code=end

