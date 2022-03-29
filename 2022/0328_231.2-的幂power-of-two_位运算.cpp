/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
// 用n & (n - 1) == 0检查n是否为2的某次方
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        return n > 0 && (n & (n - 1)) == 0;
        // 2的幂次方一定是正数，所以n>0不要忘记
    }
};
// @lc code=end

