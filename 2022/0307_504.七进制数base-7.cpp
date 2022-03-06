/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
/*
举例:
100 ÷ 7 = 14 …… 2
14 ÷ 7 = 2 …… 0
2 ÷ 7 = 0 …… 2
因为最后一位余数是经过多次除以7才得到
因此它是最高位
读数字的时候从最后的余数向前读
即位数从高到低
202

负数同理
-7 ÷ 7 = -1 …… 0
-1 ÷ 7 = 0 …… -1
-10
*/
/*
易错点:
+'0'表示转换为char,如果是-7,WA："/0",所以num正负也分类讨论一下
*/
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        string res;
        bool isNegative = num < 0; // 是否是负数
        if (isNegative)
            num = -num; // 取绝对值
        while (num > 0)
        {
            res.push_back(num % 7 + '0'); // 数字+'0'表示转换为char
            num /= 7;
        }
        if (isNegative)
            res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
