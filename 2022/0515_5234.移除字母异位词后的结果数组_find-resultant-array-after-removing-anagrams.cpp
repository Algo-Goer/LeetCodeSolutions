/*
移除字母异位词后的结果数组
给你一个下标从0开始的字符串words，其中words[i]由小写英文字符组成
在一步操作中，需要选出任一下标i，从words中删除words[i]。其中下标i需要同时满足下述两个条件：
0 < i < words.length
words[i - 1]和words[i]是字母异位词

只要可以选出满足条件的下标，就一直执行这个操作
在执行所有操作后，返回 words。可以证明，按任意顺序为每步操作选择下标都会得到相同的结果

字母异位词是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。例如，"dacb" 是 "abdc" 的一个字母异位词
*/

class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        // 如果相邻的字母是异位词，就删除后一个字母
        for (int i = 0; i < words.size() - 1; ++i)
        {
            if (isAnagram(words[i], words[i + 1]))
            {
                words.erase(words.begin() + i + 1);
                --i;
            }
        }
        return words;
    }
    

    bool isAnagram(string &s1, string &s2)
    {
        if (s1.size() != s2.size())
            return false;
        int count[26] = {0};
        for (int i = 0; i < s1.size(); ++i)
        {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (count[i] != 0)
                return false;
        }
        return true;
    }
};