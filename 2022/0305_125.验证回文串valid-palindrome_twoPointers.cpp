/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
/*
字符串API应用 回文串
s长度大于0,就不考虑长度为0的情况了
*/
class Solution
{
public:
    bool isPalindrome(string s)
    {
        /*
        左指针从左往右遍历,右指针从右往左遍历,如果指向的字符不同则返回false;如果两指针重合,则跳出循环
        */

        /*
        易错点
        while (!isalnum(s[left]) && left < right)里没有left < right会出现Runtime Error
        while (!isalnum(s[right]) && left < right)同理
        if (left < right)也不可少
        因为++left;--right;
        */

        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            while (!isalnum(s[left]) && left < right) // 非字母数字
                ++left;                               // 跳过
            while (!isalnum(s[right]) && left < right)
                --right;
            if (left < right)
            {
                if (tolower(s[left]) != tolower(s[right])) // 全部转换为小写字母
                {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
};
// @lc code=end
