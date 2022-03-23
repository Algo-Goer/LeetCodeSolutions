/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
/*
类同LeetCode942.增减字符串匹配

本题要求时间复杂度为O(n)

贪心&子序列
*/
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
        /*
        如果取等号
        Wrong Answer 25/26 cases passed (N/A)
        Testcase [0,0]
        Answer 2
        Expected Answer 1
        */
            return nums.size();
        int curDiff = 0; // 当前差值
        int preDiff = 0; // 前差值
        int result = 1;  // 记录峰值个数，默认最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            curDiff = nums[i + 1] - nums[i];
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0))
            {
                result++; 
                preDiff = curDiff; // 更新前差值
            }
        }
        return result;
    }
};
// @lc code=end
