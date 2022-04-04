/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
// code2 Two Pointers
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};
// @lc code=end
