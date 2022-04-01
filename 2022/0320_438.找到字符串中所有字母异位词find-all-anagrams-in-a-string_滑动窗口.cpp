/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
/*
在字符串s中构造一个长度与字符串p的长度相同的滑动窗口，
并在滑动窗口中维护窗口中每种字母的数量
当窗口中每种字母的数量与字符串p中每种字母的数量相同时，
则说明当前窗口为字符串p的异位词
*/
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        if (s.size() < p.size())
            return res;
        vector<int> p_count(26, 0); // 字符串p中每种字母的数量
        vector<int> s_count(26, 0);
        for (auto &ch : p) // 统计字符串p中每种字母的数量
        {
            p_count[ch - 'a']++; // 记录p字符串的字母频次
        }
        for (auto &ch : s.substr(0, p.size())) // s.substr(0, p.size()) 返回s的前p.size()个字符
        {
            s_count[ch - 'a']++; // 记录s字符串前p.size()个字母的频次
        }
        if (s_count == p_count) // 判断前p.size()个字符是否相等
            res.push_back(0);  // 则第一个异位词的索引为0
        for (int i = 1; i < s.size() - p.size() + 1; ++i)
        {
            s_count[s[i - 1] - 'a']--; // 滑动窗口每向右滑动一次，就少统计一次离开窗口的字符
            s_count[s[i + p.size() - 1] - 'a']++;   // 多统计一次进入窗口的字符
            if (s_count == p_count)
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end
