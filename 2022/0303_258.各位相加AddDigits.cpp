/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
/*
题目要求O(1)的时间复杂度
38 = 27 + (3 + 8)
11 = 9 + (1 + 1)
num除以9得到的余数
*/
class Solution
{
public:
    int addDigits(int num)
    {
        /*
        如果num>0:num%9为9,则返回9,其余返回num%9
        如果num=0:返回0
        */
        if (num == 0)
            return 0;
        return num % 9 == 0 ? 9 : num % 9;
        // return num % 9 == 0 ? 9 : num % 9; 通过测试用例：1100 / 1101 输入：0 输出：9 预期结果：0
        // return num % 9; // 通过测试用例：981 / 1101 输入：9 输出：0 预期结果：9
    }
};
// @lc code=end
