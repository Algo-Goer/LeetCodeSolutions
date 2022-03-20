/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
/*
哈希表
对于每个字符串，用长度为26的数组记录每个字母出现的频次。
用map分类计数
符合条件的放在一起
*/
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (auto &str : strs)
        {
            string key = str;             // 先拷贝一份
            sort(key.begin(), key.end()); // 排序
            m[key].push_back(str);        // 放入map
        }
        vector<vector<string>> res;
        for (auto &p : m)
        {
            res.push_back(p.second);
        }
        return res;
    }
};
// @lc code=end
