/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
/*
互为字母异位词的两个字符串包含的字母相同，因此对两个字符串分别排序后得到的字符串一定相同
故可以将排序之后的字符串作为哈希表的key
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
            sort(key.begin(), key.end()); // 按字母顺序排序key，互为异位词的话排序后key一定是相同的
            m[key].push_back(str);        // 把str放入key对应的vector中
            // m[key] 表示key对应的vector
        }
        vector<vector<string>> res;
        for (auto &p : m)  // 将map中的vector拷贝到res中
        {
            res.push_back(p.second);
        }
        return res;
    }
};
// @lc code=end
