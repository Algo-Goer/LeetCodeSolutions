/*
给你一个字符串数组 words 和一个字符串 pref 。
返回 words 中以 pref 作为 前缀 的字符串的数目。
字符串 s 的 前缀 就是  s 的任一前导连续字符串。
*/
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        int count = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            if (words[i].substr(0, pref.size()) == pref)
                count++;
        }   
        return count;
    }
};
// 一次通过