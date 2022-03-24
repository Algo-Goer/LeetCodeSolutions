/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
/*
双指针
空间复杂度O(1)
*/
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int i = s.size() - 1, j = t.size() - 1;
        int skipS = 0, skipT = 0;
        while (i >= 0 || j >= 0)
        {
            while (i >= 0)
            {
                if (s[i] == '#')
                {
                    skipS++, i--;
                }
                else if (skipS > 0)
                {
                    skipS--, i--;
                }
                else
                {
                    break;
                }
            }
            while (j >= 0)
            {
                if (t[j] == '#')
                {
                    skipT++, j--;
                }
                else if (skipT > 0)
                {
                    skipT--, j--;
                }
                else
                {
                    break;
                }
            }
            if (i >= 0 && j >= 0)
            {
                if (s[i] != t[j])
                    return false;
            }
            else  
            {
                if (i >= 0 || j >= 0)
                    return false;
            }
            i--, j--;
        }
        return true;
    }
};
// @lc code=end
