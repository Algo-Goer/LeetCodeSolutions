/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
// code1 双重循环枚举，毕竟是Easy，所以数量级可以用枚举
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i)
        {
            int sum = 0;
            for (int j = 0; j <= i; ++j)
            {
                sum += nums[j];
            }
            ret.push_back(sum);
        }
        return ret;
    }
};
// @lc code=end
