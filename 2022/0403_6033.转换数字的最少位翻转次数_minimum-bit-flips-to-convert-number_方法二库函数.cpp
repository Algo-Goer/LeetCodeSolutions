/*
6033. 转换数字的最少位翻转次数
一次位翻转定义为将数字x二进制中的一个位进行翻转操作
即将0变成1或者将1变成0
比方说x = 7 二进制表示111
我们可以选择任意一个位（包含没有显示的前导0）并进行翻转
比方说我们可以翻转最右边一位得到110 或者翻转右边起第二位得到101
或者翻转右边起第五位（这一位是前导 0 ）得到 10111 等等

给你两个整数 start 和 goal ，请你返回将 start 转变成 goal 的 最少位翻转 次数
*/

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        return __builtin_popcount(start ^ goal); // __builtin_popcount(x) 返回x中1的个数
    }
};