/*
 * @lc app=leetcode.cn id=2119 lang=cpp
 *
 * [2119] 反转两次的数字
 */

// @lc code=start
// 判断末尾是否为0的第二种方法：不需要转字符串，该数除以10的余数是否为0
class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num == 0 || num % 10 != 0;
    }
};
// @lc code=end

