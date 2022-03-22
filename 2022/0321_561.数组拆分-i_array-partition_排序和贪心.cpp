/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */

// @lc code=start
/*
贪心算法
让最大的数跟最大或次大的数字在一起
*/
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i += 2)
        {
            res += nums[i];
        }
        return res;
    }
};
// @lc code=end
