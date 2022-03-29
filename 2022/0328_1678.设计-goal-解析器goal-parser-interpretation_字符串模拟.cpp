/*
 * @lc app=leetcode.cn id=1678 lang=cpp
 *
 * [1678] 设计 Goal 解析器
 */

// @lc code=start
class Solution
{
public:
    string interpret(string command)
    {
        string res;
        for (int i = 0; i < command.size();)
        {
            if (command[i] == 'G')
            {
                res += 'G';
                i++;
            }
            else if (command[i] == '(' && command[i + 1] == ')')
            {
                res += 'o';
                i += 2;
            }
            else if (command[i] == '(' && command[i + 1] == 'a')
            {
                res += "al";
                /*
                res += 'al';
                Wrong Answer 7/105 cases passed (N/A)
                Testcase "G()(al)"
                Answer "Gol"
                Expected Answer "Goal"
                */
                i += 4;
            }
        }
        return res;
    }
};
// @lc code=end
