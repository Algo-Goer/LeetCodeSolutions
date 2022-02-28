/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start
// 字符串题目
/*
(a+bi)*(c+di)=(ac-bd)+(ad+bc)i
分词:
find()
substr()
字符串string转化为数字int：
stoi()
*/
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) 
    {
        int pos1 = num1.find('+'); // 找到第一个加号的位置
        int pos2 = num2.find('+');
        int a = stoi(num1.substr(0, pos1)), b = stoi(num1.substr(pos1 + 1, num1.size() - pos1 - 2));
        // num1.size() - pos1 - 2表示num1的虚部的长度:len-1-(pos1+1)
        // substr()函数的第二个参数是字符串长度
        // stoi()函数将字符串转化为数字
        int c = stoi(num2.substr(0, pos2)), d = stoi(num2.substr(pos2 + 1, num2.size() - pos2 - 2));

        string ans = to_string(a * c - b * d) + '+' + to_string(a * d + b * c) + 'i';
        // to_string()函数将数字转化为字符串
        return ans;
    }
};

// @lc code=end

