/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
/*
先排除s和t不相等的情况，直接返回false
哈希表
t和s互为异位词等价于：两个字符串中字符出现的种类、次数都相等
由于s和t仅包含26个小写字母，因此可以维护一个长度为26的频次数组table
遍历s，记录字母频次
遍历t，减去table中对应频次
如果出现table[i]<0，说明t包含一个不在s中的额外字符，返回false
如果出现table[i]>0，说明t包含一个多余字符，返回false
*/
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> table(26, 0); // 字母频次数组
        for (auto &ch : s)
        {
            table[ch - 'a']++; // ch -'a'是为了转换为0-25的数字
        }
        for (auto &ch : t)
        {
            table[ch - 'a']--;
        }
        for (auto &freq : table)
        {
            if (freq != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
