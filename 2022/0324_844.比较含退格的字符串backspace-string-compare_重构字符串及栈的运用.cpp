/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
/*
用字符串来模拟栈
遇到'#'就把栈顶元素pop出，前提是栈非空
如果是普通字符就直接入栈
*/
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        // 方法一：重构字符串，需要空间复杂度O(m + n)
        return build(s) == build(t);
    }
    string build(string str)
    {
        string res;
        for (char ch : str)
        {
            if (ch != '#')
                res.push_back(ch);
            else if (!res.empty())
                res.pop_back();
        }
        return res;
    }
};
// @lc code=end
