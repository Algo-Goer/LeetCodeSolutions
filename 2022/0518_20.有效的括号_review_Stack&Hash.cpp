/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    unordered_map<char, char> m = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (m.find(c) != m.end()) // 如果是左括号
                st.push(m[c]);        // 则把对应右括号入栈
            // 如果是不成对的右括号，或不是正确顺序的右括号，则返回false
            else if (st.empty() || st.top() != c)
                return false;
            // 如果是正确顺序的右括号，就出栈
            else
                st.pop();
        }
        return st.empty();
    }
};
// @lc code=end
