#
# @lc app=leetcode.cn id=1791 lang=python3
#
# [1791] 找出星型图的中心节点
#

# @lc code=start
'''
有一个无向的星型图
由n个编号从1到n的节点组成
星型图有一个中心节点
并且恰有n-1条边将中心节点与其他每个节点连接起来
给你一个二维整数数组edges
其中edges[i] = [ui, vi]表示在节点 ui 和 vi 之间存在一条边
请你找出并返回edges所表示星型图的中心节点
'''

'''
对edges的每一个起始点和终止点进行储存,分别构建起始点数组和终止点数组
count计数:出现n次的那个数字即中心节点
'''
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        n = len(edges)
        starts = [0] * n
        ends = [0] * n
        for i in range(n):
            starts[i] = edges[i][0]    # 储存全部起始节点
            ends[i] = edges[i][1]      # 储存全部终止节点
        # 对全部起始节点用count计数，时间复杂度基于Hash，所以为O(1)
        countStarts = collections.Counter(starts)
        # 对全部终止节点用count计数
        countEnds = collections.Counter(ends)
        # 对两组计数分别进行逆序排序
        countStarts = sorted(countStarts.items(), key=lambda x:x[1], reverse=True) 
        # key=lambda x:x[1]表示按照countStarts的值进行排序，reverse=True表示逆序
        countEnds = sorted(countEnds.items(), key=lambda x:x[1], reverse=True)
        # 将countStarts和countEnds中第一个元素的value进行比较
        max = countStarts[0][1] if countStarts[0][1] > countEnds[0][1] else countEnds[0][1]
        # 返回max对应的key
        return countStarts[0][0] if countStarts[0][1] == max else countEnds[0][0]


# @lc code=end

