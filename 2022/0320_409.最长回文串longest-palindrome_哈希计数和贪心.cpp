/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
/*
贪心
*/
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> table;
        int ans = 0;
        for (char c : s)
        {
            table[c]++;
        }
        for (auto &p : table)
        {
            ans += p.second / 2 * 2;
        }
        return ans == s.size() ? ans : ans + 1;
    }
};
// @lc code=end
