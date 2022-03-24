/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start

class Solution
{
public:
    string removeDuplicates(string s)
    {
        string res;
        for (char ch : s)
        {
            if (!res.empty() && res.back() == ch) // string.back() 返回string的最后一个字符
            {
                res.pop_back();
            }
            else
            {
                res.push_back(ch);
            }
        }
        return res;
    }
};
// @lc code=end
