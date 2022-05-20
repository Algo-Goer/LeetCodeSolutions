/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> m;
        for (auto c : s)
        {
            m[c]++;
        }
        for (auto c : t)
        {
            m[c]--;
        }
        for (auto &freq : m)
        {
            if (freq.second != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
