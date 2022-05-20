/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
// Hashmap计数 另外：magazine 中的每个字符只能在 ransomNote 中使用一次
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
            return false;
        unordered_map<char, int> m;
        for (auto c : magazine)
        {
            m[c]++;
        }
        for (auto c : ransomNote)
        {
            if (m[c] == 0)  return false;
            m[c]--;
        }
        return true;
    }
};
// @lc code=end
