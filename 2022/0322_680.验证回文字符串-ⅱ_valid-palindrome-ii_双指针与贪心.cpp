/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
/*
双指针+贪心，s只由小写英文字母组成
LC125.验证回文串（双指针），字符串s由ASCII字符组成，有大小写英文字母、空格和各类标点符号
*/
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1); // 判断是否为回文串
            }
            ++left;
            --right;
        }
        return true;
    }
    bool isPalindrome(string s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
// @lc code=end
