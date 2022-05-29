/*
 * @lc app=leetcode.cn id=2178 lang=cpp
 *
 * [2178] 拆分成最多数目的正偶数之和
 */

// @lc code=start
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 != 0)
            return {};
        vector<long long> res;
        long cur = 2;
        while (finalSum >= cur)
        {
            res.push_back(cur);
            finalSum -= cur;
            cur += 2;
        }
        // [2,4,6,8] finalSum = 16 - 8 = 8 < cur = 10
        // 8 + finalSum = 8 + 8 = 16
        // [2,4,6,16]
        res[res.size() - 1] += finalSum;
        return res;
    }
};
// @lc code=end

