/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
/*
互为字母异位词的两个字符串包含的字母相同，因此两个字符串中的相同字母出现的次数一定相等，
故可以将每个字母出现的次数使用字符串表示，作为哈希表的key

题目中字符串只包含小写字母，因此可以用长度为26的数组记录每个字母出现的次数
*/
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        map<vector<int>, vector<string>> m;
        for (auto &str : strs)
        {
            vector<int> key(26, 0);
            string s = str; // 先拷贝一份
            for (auto &c : s)
            {
                key[c - 'a']++;
            }
            m[key].push_back(str);
        }
        for (auto &p : m)
        {
            res.push_back(p.second);
        }
        return res;
    }
};
// @lc code=end
