/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
/*
t和s互为异位词：
两个字符串排序后相等

如果t和s长度不等，直接返回false
如果t和s长度相等，排序后字符串相等，返回true，反之返回false
*/
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
// @lc code=end
