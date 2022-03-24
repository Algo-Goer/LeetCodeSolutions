/*
 * @lc app=leetcode.cn id=1544 lang=cpp
 *
 * [1544] 整理字符串
 */

// @lc code=start
// 栈的运用
class Solution
{
public:
    string makeGood(string s)
    {
        string res;
        for (char ch : s)
        {
            if (!res.empty() && tolower(res.back()) == tolower(ch) && res.back() != ch)
            {
                res.pop_back();
            }
            else
                res.push_back(ch);
        }
        return res;
    }
};
// @lc code=end
