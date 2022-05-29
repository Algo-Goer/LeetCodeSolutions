/*
 * @lc app=leetcode.cn id=2177 lang=cpp
 *
 * [2177] 找到和为给定整数的三个连续整数
 */

// @lc code=start
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3 == 0)
            return {num / 3 - 1, num / 3, num / 3 + 1};
        return {}; // 别忘了最后一句返回
    }
};
// @lc code=end

