/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
/**
 * 本题只能交易一次,买和卖各一次
 * 
 * 动态规划
 * 状态定义：dp[i][j]为第i天结束时持股状态为j时持有的现金/利润数，j=0表示空仓，j=1表示持有股票。
 * 下标为i的这一天的计算结果包含了[0,i]所有信息
 * 最后输出dp[n-1][0]
 * 状态转移方程：dp[i][j] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 * 初始条件：dp[0][0] = 0, dp[0][1] = -prices[0]
 * 
 * 关于状态转移方程的详细阐释：
 * 今天空仓,分两种：
 * 1、昨天持有股票,今天卖出,则今天空仓 -- dp[i-1][1] + prices[i]
 * 2、昨天没有持有股票,今天不操作 -- dp[i-1][0]
 * dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1] + prices[1])
 * 
 * 今天持有股票,分两种：
 * 1、昨天持有,今天不操作 -- dp[i-1][1]
 * 2、昨天没有持有,今天买入 -- dp[i-1][0] - prices[i]
 * dp[i][1] = Math.max(dp[i-1][1], - prices[i])
 * 
 * 最大利润是max(dp[i][0], dp[i][1])
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        // 新建一个二维数组,用于存储状态及状态转移方程的结果
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));    // 空间复杂度O(n^2)
        // 初始状态
        dp[0][0] = 0;  // 第1天不持有股票
        dp[0][1] = - prices[0];  // 第1天持有股票
        // 状态转移方程
        // 遍历
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1],  - prices[i]);
        }
        return dp[n-1][0];
    }
};
// @lc code=end

