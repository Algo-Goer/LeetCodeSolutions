/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 *
 * [2104] 子数组范围和
 */

// @lc code=start
// 母题LeetCode_907_子数组的最小值之和
/*
sum(range) = sum(max - min) = sum(max) - sum(min)
对于nums中的每个数字nums[i], ans = nums[i] * range

对于nums中的每个数字nums[i],先找离nums[i]左右两边最近的大于nums[i]的数字,这样nums[i]就在这个范围内充当最小值了
对于nums中的每个数字nums[i],再找离nums[i]左右两边最近的小于nums[i]的数字,这样nums[i]就在这个范围内充当最大值

注意:这道题是有重复值的单调栈情况
*/
using LL = long long;
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> Stack;
        vector<int> nextSmaller(n, n);
        for (int i = 0; i < n; ++i)
        {
            while (!Stack.empty() && nums[Stack.top()] > nums[i])
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

        vector<int> prevSmaller(n, -1);
        for (int i = n - 1; i >= 0; --i)
        {
            while (!Stack.empty() && nums[Stack.top()] >= nums[i])
            {
                prevSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
        while (!Stack.empty())
        {
            Stack.pop(); // 清空栈
        }

        vector<int> nextGreater(n, n);
        for (int i = 0; i < n; ++i)
        {
            while (!Stack.empty() && nums[Stack.top()] < nums[i])
            {
                nextGreater[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
        while (!Stack.empty())
        {
            Stack.pop(); // 清空栈
        }

        vector<int> prevGreater(n, -1);
        for (int i = n - 1; i >= 0; --i)
        {
            while (!Stack.empty() && nums[Stack.top()] <= nums[i])
            {
                prevGreater[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }

        LL ret = 0;
        for (int i = 0; i < n; ++i)
        {
            int l = prevGreater[i];
            int r = nextGreater[i];
            ret += (LL)nums[i] * (i - l) * (r - i); // LL防止溢出
        }
        for (int i = 0; i < n; ++i)
        {
            int l = prevSmaller[i];
            int r = nextSmaller[i];
            ret -= (LL)nums[i] * (i - l) * (r - i); // LL防止溢出
        }
        return ret;
    }
};
// @lc code=end
