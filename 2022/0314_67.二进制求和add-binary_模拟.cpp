/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1, j = b.size() - 1, carry = 0; // carry表示进位
        string res;
        while (i >= 0 || j >= 0) // 当两个字符串都遍历完成时，退出循环
        {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0'; // 将字符串转换为数字
            if (j >= 0)
                sum += b[j--] - '0';
            res.push_back(sum % 2 + '0'); // 将和转换为字符串
            carry = sum / 2;              // 计算进位
        }
        if (carry)
            res.push_back(carry + '0');  // 如果还有进位，则添加进位
        reverse(res.begin(), res.end()); // 将字符串反转
        return res;
    }
};
// @lc code=end
