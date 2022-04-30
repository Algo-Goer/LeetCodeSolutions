/*
统计是给定字符串前缀的字符串数目
给你一个字符串数组 words 和一个字符串 s ，其中 words[i] 和 s 只包含 小写英文字母 。
请你返回 words 中是字符串 s 前缀 的 字符串数目 。
一个字符串的 前缀 是出现在字符串开头的子字符串。子字符串 是一个字符串中的连续一段字符序列。

输入：words = ["a","b","c","ab","bc","abc"], s = "abc"
输出：3
解释：
words 中是 s = "abc" 前缀的字符串为：
"a" ，"ab" 和 "abc" 。
所以 words 中是字符串 s 前缀的字符串数目为 3 。
*/
class Solution
{
public:
    int countPrefixes(vector<string> &words, string s)
    {
        int res = 0;
        for (auto word : words)
        {
            int size = word.size();
            if (size > s.size())
                continue;  // 增加鲁棒性测试
            if (s.substr(0, size) == word)
                res++;
        }
        return res;
    }
};