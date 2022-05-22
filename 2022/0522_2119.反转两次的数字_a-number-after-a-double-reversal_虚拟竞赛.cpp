/*
 * @lc app=leetcode.cn id=2119 lang=cpp
 *
 * [2119] 反转两次的数字
 */

// @lc code=start
class Solution {
public:
    bool isSameAfterReversals(int num) {
        string str = to_string(num);
        if (str.size() == 1) return true;
        int n = str.size();
        if (str[n - 1] == '0') return false;
        return true;
    }
};
// @lc code=end

