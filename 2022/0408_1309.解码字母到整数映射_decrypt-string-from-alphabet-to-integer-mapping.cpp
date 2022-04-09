/*
 * @lc app=leetcode.cn id=1309 lang=cpp
 *
 * [1309] 解码字母到整数映射
 */

// @lc code=start
class Solution
{
public:
    string freqAlphabets(string s)
    {
        string ans;
        for (int i = 0; i < s.size();)
        {
            if (i + 2 < s.size() && s[i + 2] == '#')
            {
                ans += ((s[i] - '0') * 10 + (s[i + 1] - '0') - 1) + 'a'; // 例如s="10#", s[i]-'0'=1, 10+0-1=9, 9+'a'即'j'
                i += 3;
            }
            else
            {
                ans += s[i] + '0'; // 例如s="1", '1'对应ASCII为49, '0'对应ASCII为49, 加起来97刚好是小写字母'a'
                i++;
            }
        }
        return ans;
    }
};
// @lc code=end
