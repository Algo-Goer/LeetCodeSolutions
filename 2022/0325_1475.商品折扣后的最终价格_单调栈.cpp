/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start
// 单调栈
class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        vector<int> res(prices); // copy原数组
        stack<int> monotone_stack; // 单调栈
        // 找右侧下一个更小元素，所以是单调递增栈，从栈底到栈顶非严格从小到大（含等号）
        for (int i = 0; i < prices.size(); ++i) 
        {
            while (!monotone_stack.empty() && prices[i] <= prices[monotone_stack.top()]) // 题目中说可取等号 
            {
                res[monotone_stack.top()] = prices[monotone_stack.top()] - prices[i]; 
                monotone_stack.pop();  
            }
            monotone_stack.push(i); 
        }
        return res;
    }
};

// @lc code=end
