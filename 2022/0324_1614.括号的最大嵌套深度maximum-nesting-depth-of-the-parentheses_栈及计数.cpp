/*
 * @lc app=leetcode.cn id=1614 lang=cpp
 *
 * [1614] 括号的最大嵌套深度
 */

// @lc code=start
class Solution
{
public:
    int maxDepth(string s)
    {
        // 遍历s，如果为'('，则深度加1；如果为')'，则深度减1
        // depth为当前深度
        // maxDepth为最大深度
        int depth = 0, maxDepth = 0;
        for (char c : s)
        {
            if (c == '(')
                depth++;
            else if (c == ')')
                depth--;
            maxDepth = max(maxDepth, depth); // C++不用写max宏定义
        }
        return maxDepth;
    }
};
// @lc code=end
