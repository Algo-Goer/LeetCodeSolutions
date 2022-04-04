/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start
class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        stack<int> s;
        vector<int> res(prices);
        for (int i = 0; i < prices.size(); ++i)
        {
            while (!s.empty() && prices[i] <= prices[s.top()])
            {
                res[s.top()] = prices[s.top()] - prices[i];
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
// @lc code=end
