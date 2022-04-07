/*
 * @lc app=leetcode.cn id=1856 lang=cpp
 *
 * [1856] 子数组最小乘积的最大值
 */

// @lc code=start
/*
单调栈&前缀和
把当前元素假设为最小值，找出以它作为最小值的所有区间（类似[2104]、[907])，利用前缀和可以求出各个区间值
比如[1,2,3,2]
假设1为最小值，1作为最小值的区间个数有4个：[1][1,2][1,2,3][1,2,3,2],1,3,6,8,最大值8
假设2为最小值，2最为最小值的区间个数有3个，[2][2,3][2,3,2],2,5,7,最大值2*7=14
假设3为最小值，3作为最小值的区间个数有1个，[3],3,最大值9
假设2为最小值，2作为最小值的区间个数有3个，[3,2][2],5,2,最大值5*2=10
14
*/
/*
monotonic stack
subarray: sum * minVal
a=prevSmaller[i]
b=nextSmaller[i]
*/
typedef long long ll;
class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prevSmaller(n, -1); // 小技巧，没有prevSmaller，比如[5,4,3,2,1]所有元素都没有prevSmaller，所以设定虚拟值index为-1
        vector<int> nextSmaller(n, n);  // 同理，没有nextSmaller，比如[1,2,3,4,5]所有元素都没有nextSmaller，所以设定虚拟值index为n

        stack<int> Stack;
        // 求nextSmaller，严格单调递增栈
        for (int i = 0; i < n; ++i)
        {
            while (!Stack.empty() && nums[Stack.top()] > nums[i]) // 不取等号，栈越大越好
            {
                nextSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
        while (!Stack.empty())
        {
            Stack.pop(); // 清空栈
        }

        // 求prevSmaller
        for (int i = n - 1; i >= 0; --i)
        {
            while (!Stack.empty() && nums[Stack.top()] > nums[i]) // 不取等号，栈越大越好
            {
                prevSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }

        vector<ll> presum(n);
        presum[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            presum[i] = presum[i - 1] + nums[i];
        }

        ll ret = 0; // 全局变量：最大值
        ll M = 1e9 + 7;
        for (int i = 0; i < n; ++i)
        {
            int a = prevSmaller[i]; // a可能是-1
            int b = nextSmaller[i];
            ll sum = presum[b - 1] - (a == -1 ? 0 : presum[a]); // b是n没有关系，这里是presum[b-1]
            ret = max(ret, sum * (ll)nums[i]);                  // 别忘记加ll，根据题意，别在这里取模
        }
        return ret % M; // module operation
    }
};
// @lc code=end
