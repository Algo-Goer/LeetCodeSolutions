/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */


// @lc code=start
// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
/**
 * 给定一个字符串s
 * 找到它的第一个不重复的字符
 * 并返回它的索引
 * 如果不存在
 * 则返回-1 
 */
// unordered_map
class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<int, int> freq;
        for (char ch: s)
        {
            freq[ch]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (freq[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

