/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 *
 * [1124] 表现良好的最长时间段
 */

// @lc code=start
// 单调栈&前缀和
class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        int n = hours.size();
        int ans = 0;
        vector<int> prefixSum(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            prefixSum[i] = prefixSum[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
        }
        stack<int> s;
        for (int i = 0; i <= n; ++i)
        {
            if (s.empty() || prefixSum[s.top()] > prefixSum[i])
                s.push(i);
        }
        for (int j = n; j >= ans; --j)
        {
            while (!s.empty() && prefixSum[j] > prefixSum[s.top()])
            {
                ans = max(ans, j - s.top());
                s.pop();
            }
           
        }
        return ans;
    }
};
/*
举例
hours=[9,9,6,0,6,6,9]
数据预处理[1,1,-1,-1,-1,-1,1]
prefixSum=[0,1,2,1,0,-1,-2,-1]
单调递减元素:0,-1,-2], 对应下标:[0,5,6], 严格单调递减栈s:[0,5,6]
j=7, prefixSum[7]=-1, prefixSum[s.top()]=prefixSum[6]=-2, -1>-2, ans=max(0, 7-6)=1, s=[0,5]
j=6, prefixSum[6]=-2, prefixSum[s.top()]=prefixSum[5]=-1, -2<-1
j=5, prefixSum[5]=-1, prefixSum[s.top()]=prefixSum[5]=-1,-1=-1
j=4, prefixSum[4]=0, prefixSum[s.top()]=prefixSum[5]=-1, 0>-1, ans=max(1, 4-5)=1, s=[0]
j=3, prefixSum[3]=1, prefixSum[s.top()]=prefixSum[0]=0, 1>0, ans=max(1, 3-0)=3, s=[]
j=2<ans=3, 不进入while循环
ans=3
*/
// @lc code=end
