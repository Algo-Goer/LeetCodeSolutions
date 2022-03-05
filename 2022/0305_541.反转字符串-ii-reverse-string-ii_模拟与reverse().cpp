/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.size();
        int i = 0;
        while (i < n)
        {
            int j = min(i + k - 1, n - 1);
            reverse(s.begin() + i, s.begin() + j + 1);
            i += 2 * k;
        }
        return s;
    }
};
// @lc code=end
