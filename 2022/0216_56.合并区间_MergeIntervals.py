#
# @lc app=leetcode.cn id=56 lang=python3
#
# [56] 合并区间
#

# @lc code=start
'''
以数组intervals表示若干个区间的集合
其中单个区间为 intervals[i] = [starti, endi]
请你合并所有重叠的区间
并返回一个不重叠的区间数组
该数组需恰好覆盖输入中的所有区间
'''
# 区间题目,按照区间的起始位置排序,然后合并:
# 如果当前区间的起始位置<=前一个区间的结束位置，则结束位置取重叠区间的最大值（两重叠区间合并）
# 如果当前区间的起始位置>前一个区间的结束位置，则直接添加到结果集

# 1 <= intervals.length <= 10^4

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x:x[0]) # 根据起始位置排序
        res = []
        for i in range(len(intervals)): 
            # 如果res为空或者当前区间的起始位置大于上一个区间的结束位置，则直接合并
            # 不能写等号，否则[[1,4],[4,5]]输出就为[[1,4],[4,5]]而不是[[1,5]]
            if not res or res[-1][-1] < intervals[i][0]: # res[-1][1]表示上一个区间的结束位置
                res.append(intervals[i])
            else:
                res[-1][-1] = max(res[-1][-1], intervals[i][-1])
        return res

      
        
# @lc code=end

