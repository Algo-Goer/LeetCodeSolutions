/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 */

// @lc code=start
/**
 * 给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）
 * 字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"
 */
/**
 * 思路：
 * 哈希、计数
 * 字母balloon需要2个l和o，可把字母l和o的数量分别除以2，返回min{各个字母数量}即可以构成单词的数量
 */
// 哈希、unordered_map
class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        unordered_map<char, int> m;
        for (char c : text)
        {
            m[c]++;
        } 
        int res = m['b'];
        res = min(res, m['a']);
        res = min(res, m['l'] / 2);
        res = min(res, m['o'] / 2);
        res = min(res, m['n']);
        return res;
    }
};
// @lc code=end

