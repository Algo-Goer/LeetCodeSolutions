/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 *
 * [1673] 找出最具竞争力的子序列
 */

// @lc code=start
/*
单调栈&贪心，类[402]移掉K位数字
要让剩下数字最小，就要保证靠前数字尽可能小（贪心），尽量去掉左边的大数字；如果从左往右已经依次递增，那就从最右边开始删除数字
找下一个更小的数字-单调递增栈
*/
class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int d = nums.size() - k; // 需要删除d个数字，这样跟[402]思路一致了
        vector<int> s;
        for (auto &n : nums)
        {
            while (d > 0 && !s.empty() && n < s.back())
            {
                s.pop_back();
                d--;
            }
            s.push_back(n);
        }
        while (s.size() > k)
        {
            s.pop_back();
        }
        return s;
    }
};
// @lc code=end
