/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
// 模拟
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int dif = 0;
        int max = 0;
        for (int i = prices.size() - 1; i > 0; --i)
        {
            dif += prices[i] - prices[i - 1];
            if (dif > max)
                max = dif;
            else if (dif < 0)
                dif = 0;
        }
        return max;
    }
};
// @lc code=end

