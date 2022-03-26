/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
// 双指针
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string res;
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size())
        {
            res += word1[i];
            res += word2[j];
            i++;
            j++;
        }
        if (i < word1.size())
        // substr()返回一个新的字符串，它是原字符串的一个子串，由beginIndex和endIndex指定的
            res += word1.substr(i); // 将word1中剩余的字符添加到res中
        if (j < word2.size())
            res += word2.substr(j);
        return res;
    }
};
// @lc code=end
