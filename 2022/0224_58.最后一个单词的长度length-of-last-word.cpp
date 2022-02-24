/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
/*
跟第66题挺像
第66题：逆序遍历，第一次碰到非9元素
本题：逆序遍历，第一次遇到非空元素
*/
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size();
        int res = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] != ' ')
                res++;
            else if (res != 0)
                break;
        }
        return res;
    }
};
// @lc code=end
