/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
/*
Monotonic Stack + 循环数组
*/
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1); // 初始化为-1
        stack<int> st;
        for (int i = 0; i < 2 * n; ++i) // 循环数组
        {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num)
            {
                ans[st.top()] = num;
                st.pop();
            }
            st.push(i % n);
        }
        return ans;
    }
};
// @lc code=end
