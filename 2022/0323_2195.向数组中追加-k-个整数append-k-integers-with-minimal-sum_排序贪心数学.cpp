/*
 * @lc app=leetcode.cn id=2195 lang=cpp
 *
 * [2195] 向数组中追加 K 个整数
 */

// @lc code=start
/*
这道题之前比赛没做出来，当时也知道是贪心

排序、贪心、枚举
*/
class Solution
{
public:
    long long minimalKSum(vector<int> &nums, int k)
    {

        // 排序
        sort(nums.begin(), nums.end());
        // 去重
        int n = nums.size();
        long long d = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] <= k)
            {
                d += nums[i];
                ++k;
            }
        }
        return (1LL + k) * k / 2 - d; // 1LL 表示long long
    }
};
// @lc code=end
