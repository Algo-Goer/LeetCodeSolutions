/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
/*
单调栈
如果从左往右遍历，价格依次递减，那么返回的就都是1
如果从左往右遍历，遇到有价格不递减（含等号）的，这时候返回的就会大于1
所以我们要寻找下一个大于等于的数，就要构建一个非严格单调递减栈
同时记录对应的天数，一旦当前的数大于栈顶的数，就要pop出栈顶的数，并且day加1

本题是Medium难度的原因在于增加了一个变量day去统计小于等于当前价格的天数
*/
class StockSpanner
{
public:
    stack<int> prices; // 非单调递减栈
    vector<int> days;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int day = 1;
        while (!prices.empty() && prices.top() <= price)
        {
            prices.pop();
            day += days.back();
            days.pop_back();
        }
        prices.push(price);
        days.push_back(day);
        return day;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
