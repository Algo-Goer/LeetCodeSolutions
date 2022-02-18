#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
'''
给定一个数组prices
它的第i个元素prices[i]表示一支给定股票第i天的价格
你只能选择 某一天 买入这只股票
并选择在 未来的某一个不同的日子 卖出该股票
设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润
如果你不能获取任何利润
返回 0 。

输入[7,1,5,3,6,4]
输出5
解释
在第 2 天股票价格 = 1的时候买入
在第 5 天股票价格 = 6的时候卖出
最大利润 = 6-1 = 5 。
注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格
同时你不能在买入前卖出股票。

1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4
'''
'''
动态规划,记录第i天及之前的最便宜的股票(不断更新),计算第i天的最大利润
'''

from selectors import EpollSelector


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = float('inf')  # 正无穷
        maxProfit = 0
        for i in range(len(prices)):
            if prices[i] < minPrice:
                minPrice = prices[i]
            maxProfit = max(maxProfit, prices[i] - minPrice) # 更新最大利润
           
        return maxProfit

# @lc code=end

