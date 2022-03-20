/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string prefix = strs[0]; // 初始化前缀为第一个字符串
        for (int i = 1; i < strs.size(); ++i)
        {
            while (strs[i].find(prefix) != 0) // 如果前缀不在当前字符串中，则移除前缀
            {
                prefix.pop_back(); // 删除最后一个字符
                if (prefix.empty())
                    return "";
            }
        }
        return prefix;
    }
};
// @lc code=end
