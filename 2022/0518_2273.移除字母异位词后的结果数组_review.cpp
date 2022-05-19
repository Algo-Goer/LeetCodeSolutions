/*
 * @lc app=leetcode.cn id=2273 lang=cpp
 *
 * [2273] 移除字母异位词后的结果数组
 */

// @lc code=start
class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> res;
        res.push_back(words[0]);
        for (int i = 1; i < words.size(); ++i)
        {
            vector<int> A(26), B(26);
            for (char c : words[i - 1])
            {
                A[c - 'a']++; 
            }
            for (char c : words[i])
            {
                B[c - 'a']++;
            }
            for (int j = 0; j < 26; ++j)
            {
                if (A[j] != B[j])
                {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
