/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
// 完全同LeetCode_316_不同字符的最小子序列
class Solution
{
public:
    string smallestSubsequence(string s)
    {
        unordered_map<char, int> mp;   // 统计字符出现次数
        string res;                    // 用字符串模拟单调栈
        vector<bool> visit(26, false); // 记录该字符是否在栈中
        for (char c : s)
        {
            mp[c]++;
        }
        for (char c : s)
        {
            if (!visit[c - 'a'])
            {
                // 未出现在栈中，才考虑入栈
                while (!res.empty() && res.back() > c && mp[res.back()] > 0)
                {
                    visit[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(c);
                visit[c - 'a'] = true;
            }
            mp[c]--;
        }
        return res;
    }
};
// @lc code=end
