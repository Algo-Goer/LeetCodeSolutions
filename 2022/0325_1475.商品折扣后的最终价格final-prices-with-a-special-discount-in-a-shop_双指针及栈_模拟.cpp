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
        vector<int> res;
        for (int i = 0; i < prices.size(); ++i)
        {
            int j = i + 1;
            while (j < prices.size() && prices[j] > prices[i])
            {
                j++;
            }
            if (j < prices.size())
            {
                res.push_back(prices[i] - prices[j]);
            }
            else
            {
                res.push_back(prices[i]);
            }
        }
        return res;
    }
};
// @lc code=end
