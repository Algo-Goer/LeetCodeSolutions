/*
 * @lc app=leetcode.cn id=6065 lang=cpp
 *
 * [6065] 按位与结果大于零的最长组合
 */

// @lc code=start
// 统计所有位数的1的数量
// 最大为10的7次方，所以24位够用
class Solution
{
public:
    int largestCombination(vector<int> &candidates)
    {
        vector<int> bit_count(24, 0);
        for (int i = 0; i < 24; ++i)
        {
            for (int j = 0; j < candidates.size(); ++j)
            {
                if ((candidates[j] & 1) == 1)
                {
                    bit_count[i]++;
                }
                // 按位计算
                candidates[j] >>= 1;
            }
        }
        int max_count = 0;
        for (int i = 0; i < 24; ++i)
        {
            if (bit_count[i] > max_count)
                max_count = bit_count[i];
        }
        return max_count;
    }
};
// @lc code=end
