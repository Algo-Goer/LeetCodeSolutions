/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
/*
从头到尾遍历字符串，直到找到空格为止，此时找到了一个单词
交换字符串第一个字符与倒数第一个字符，随后交换第二个字符与倒数第二个字符，以此类推
原地反转，不需要额外空间
*/
class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        int i = 0;
        while (i < n)
        {
            int word_start = i;
            while (i < n && s[i] != ' ')
                i++;
            int word_end = i - 1;
            while (word_start < word_end)
                swap(s[word_start++], s[word_end--]); // 原地反转
            i++;
        }
        return s;
    }
};
// @lc code=end
