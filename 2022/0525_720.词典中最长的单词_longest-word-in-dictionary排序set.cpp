/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
// code1 unordered_set sort
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        if (words.size() == 0) return "";
        unordered_set<string> dict;
        sort(words.begin(), words.end());
        string res = "";
        for (string word : words)
        {
            if (word.size() == 1 || dict.count(word.substr(0, word.size() - 1)))
            {
                if (word.size() > res.size())
                {
                    res = word;
                }
                dict.insert(word);
            }
        }
        return res;
    }
};
// @lc code=end
