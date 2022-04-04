/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
/*
Monotonic Stack
找右边最近的更大的元素
想起了[496]下一个更大元素I Easy
为什么本题是M，[496]是E呢？因为多了一步——计算和下一个更大的元素下标之间的差值
*/
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size(), 0);
        stack<int> s;
        for (int i = 0; i < temperatures.size(); ++i)
        {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) 
            {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end
