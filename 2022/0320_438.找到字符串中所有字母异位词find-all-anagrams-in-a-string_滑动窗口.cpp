/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        if (s.size() < p.size())
            return res;
        vector<int> p_count(26, 0);
        vector<int> s_count(26, 0);
        for (auto &ch : p)
        {
            p_count[ch - 'a']++;
        }
        for (auto &ch : s.substr(0, p.size()))
        {
            s_count[ch - 'a']++;
        }
        if (s_count == p_count)
            res.push_back(0);
        for (int i = 1; i < s.size() - p.size() + 1; ++i)
        {
            s_count[s[i - 1] - 'a']--;
            s_count[s[i + p.size() - 1] - 'a']++;
            if (s_count == p_count)
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end
