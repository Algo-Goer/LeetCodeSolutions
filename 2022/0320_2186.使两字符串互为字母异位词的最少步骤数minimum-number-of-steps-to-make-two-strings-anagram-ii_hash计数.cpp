/*
 * @lc app=leetcode.cn id=2186 lang=cpp
 *
 * [2186] 使两字符串互为字母异位词的最少步骤数
 */

// @lc code=start
/*
之前没做出的比赛题
看起来跟第1347题挺像，但比第1347题稍微复杂些
*/
class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> table(26, 0); // 对于只有小写字母的题目，都可以建立长度为26的table
        for (auto &ch : s)        // 先把s中的字母频次记录到table中
        {
            table[ch - 'a']++;
        }
        for (auto &ch : t)
        {
            table[ch - 'a']--;
        }
        int res = 0;
        // 统计差值之和，用绝对值，不用考虑谁多谁少
        for (auto &freq : table)
        {
            res += abs(freq);
        }
        return res;
    }
};
// @lc code=end
