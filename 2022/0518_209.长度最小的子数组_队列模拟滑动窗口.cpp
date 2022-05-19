/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
// 队列模拟滑动窗口
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = INT_MAX, sum = 0;
        queue<int> q;
        for (auto &n : nums)
        {
            sum += n;
            q.push(n);
            while (sum >= target)
            {
                ans = min(ans, (int)q.size()); // 不加int会报错 error: no matching function for call to 'min'
                sum -= q.front();
                q.pop();
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end
