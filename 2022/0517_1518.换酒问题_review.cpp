/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 *
 * [1518] 换酒问题
 */

// @lc code=start
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int exchangeable = numBottles, ans = numBottles;
        while (exchangeable >= numExchange)
        {
            exchangeable -= numExchange;
            ++ans;
            ++exchangeable;
        }
        return ans;
    }
};
// @lc code=end
