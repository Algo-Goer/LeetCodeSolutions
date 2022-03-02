/*
 * @lc app=leetcode.cn id=553 lang=cpp
 *
 * [553] 最优除法
 */

// @lc code=start
/*
贪心、字符串拼接、整数转化为字符串
最大结果->被除数尽量大，除数尽量小
所以第一个数字作为被除数，把逗号全部改成/，在第二个数字前面加(，在最后一个数字后面加)
*/
class Solution
{
public:
    string optimalDivision(vector<int> &nums)
    {
        string res = "";
        if (nums.size() == 1)
            return to_string(nums[0]);
        if (nums.size() == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        res += to_string(nums[0]);
        res += "/(";
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            res += to_string(nums[i]);
            res += "/";
        }
        res += to_string(nums[nums.size() - 1]);
        res += ")";
        return res;
    }
};
// 一次通过
// @lc code=end
