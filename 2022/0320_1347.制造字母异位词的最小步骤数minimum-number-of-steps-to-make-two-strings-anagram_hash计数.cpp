/*
 * @lc app=leetcode.cn id=1347 lang=cpp
 *
 * [1347] 制造字母异位词的最小步骤数
 */

// @lc code=start

class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> table(26, 0);
        for (auto &ch : s)
        {
            table[ch - 'a']++;
        }
        for (auto &ch : t)
        {
            table[ch - 'a']--; // 减去t中的字母
        }
        int res = 0;
        for (auto &freq : table) // 如果freq>0，说明t中有s种没有的字符，那就需要替换
        {
            if (freq > 0)
                res += freq;
        }
        return res;
    }
};
// @lc code=end
