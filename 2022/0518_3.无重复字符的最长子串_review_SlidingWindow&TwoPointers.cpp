/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
// Sliding Window & Hashmap & Two Pointers
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> map; 
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); ++i)
        {
            map[s[i]]++;
            while (map[s[i]] > 1) map[s[j++]]--;
            res = max(res, i - j + 1);
        }
        return res;
    }
};
// @lc code=end
