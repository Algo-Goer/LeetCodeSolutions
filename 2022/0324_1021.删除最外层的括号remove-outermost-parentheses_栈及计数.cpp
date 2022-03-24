/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
/*
栈的运用
如果栈为空，那么第一个"("就是最外层的"("，L初始为1
当右括号的数量等于左括号的数量时，该位置就是最外面的右括号
*/

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        // 最外面的左括号跳过，L初始为1
        // 当右括号的数量等于左括号的数量时的位置就是最外面的右括号
        int l = 1;
        int r = 0;
        string res;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                l++;
            }
            else
            {
                r++;
            }
            if (r != l)
                res.push_back(s[i]);
            else
            {
                l = 1, r = 0; //重置
                i++;          // 跳过最外面的右括号
            }
        }
        return res;
    }
};
// @lc code=end
