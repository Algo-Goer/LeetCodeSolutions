/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
/*
Monotonic Stack
*/
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nextSmaller(n, n);  // [1,2,3,4,5,6,7],0 没有任何元素有nextSmaller，就虚拟在后面写个下标n
        vector<int> prevSmaller(n, -1); // 0,[7,6,5,4,3,2,1] 没有任何元素有prevSmaller，就虚拟在前面写个下标-1
        stack<int> Stack;
        // 求nextSmaller
        for (int i = 0; i < n; ++i)
        {
            while (!Stack.empty() && arr[Stack.top()] > arr[i]) // 当前元素小于栈顶元素对应的元素，则弹出栈顶元素
            {
                nextSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i); // 非严格单调递增栈：当前元素大于等于栈顶元素对应的元素，就入栈
        }
        // 重复利用栈，所以清空栈
        while (!Stack.empty())
            Stack.pop();
        // 求previous equal or smaller
        // 约定往左边找的时候，如果发现相同元素就停下且不能包括相同元素在边界内，而右边仍然可以
        for (int i = n - 1; i >= 0; --i)
        {
            while (!Stack.empty() && arr[Stack.top()] >= arr[i]) // 取等号
            {
                prevSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
        long ret = 0;
        long M = 1e9 + 7;
        // 再扫一遍，每个元素左右边界
        for (int i = 0; i < n; ++i)
        {
            int a = prevSmaller[i];
            /*
            2 8 5 6 5 [7 5 5 5 5 6] 2
                         ^
                    a    i          b
            */
            int b = nextSmaller[i];
            long num = arr[i] % M * (i - a) * (b - i) % M; // subarray个数，数字太大，取余
            ret = (ret + num) % M;
        }
        return ret;
    }
};
// @lc code=end
