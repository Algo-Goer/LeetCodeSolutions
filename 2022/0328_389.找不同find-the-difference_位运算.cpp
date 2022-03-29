/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
// 类似于136.只出现一次的数字
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int res = 0;
        for (auto &ch : s)
        {
            res ^= ch; // 异或运算
        }
        for (char &ch : t)
        {
            res ^= ch;
        }
        return res;
    }
};
// @lc code=end
