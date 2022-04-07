/*
 * @lc app=leetcode.cn id=962 lang=cpp
 *
 * [962] 最大宽度坡
 */

// @lc code=start
/*
[1124]的母题
找到满足A[j]>=A[i]的最大跨度[i,j]
要找出最大宽度且i<j，那么i要尽可能小，j要尽可能大。所以i从左往右遍历，j从右往左遍历

另外A[i]<=A[j]，那么A[i]要尽可能小，可以利用单调递减栈：
1. 正向遍历记录严格单调递减栈的A[i]的下标
2. 反向遍历比较A[j]与栈顶元素A[s.top()]的值，如果满足条件，则pop栈顶元素，且宽度更新，不断循环直到栈空
*/
class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        stack<int> s;
        int res = 0;
        int n = nums.size();
        s.push(0);
        for (int i = 0; i < n; ++i)
        {
            if (s.empty() || nums[s.top()] > nums[i])
                s.push(i); // 严格单调递减栈
        }
        for (int j = n - 1; j >= res; --j)
        {
            while (s.size() && nums[s.top()] <= nums[j])
            {
                int pos = s.top();
                s.pop();
                res = max(res, j - pos);
            }
        }
        return res;
    }
};
// @lc code=end
