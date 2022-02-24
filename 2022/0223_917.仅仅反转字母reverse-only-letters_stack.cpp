/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
/*
逆序-栈
先遍历一次，把所有字母保存到栈中
再遍历一次，如果是字母把栈顶元素pop出来，否则就直接copy非字母符号
*/
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
                st.push(s[i]);
        }
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
            {
                 res += st.top();
                // 把栈顶元素从栈中删除
                st.pop();
            }        
            else res += s[i];
        }
        return res;
    }
};
// @lc code=end
