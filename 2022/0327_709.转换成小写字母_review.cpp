/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
class Solution
{
public:
    string toLowerCase(string s)
    {
        string res;
        for (auto &ch : s)
        {
            if (ch >= 'A' && ch <= 'Z')
                res += ch + 32;
            else
                res += ch;
        }
        return res;
    }
};
// @lc code=end
