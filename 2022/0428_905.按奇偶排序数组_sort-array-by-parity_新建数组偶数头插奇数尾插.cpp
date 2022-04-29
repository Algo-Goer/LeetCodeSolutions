/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
// code1 新建数组，偶数头插，奇数尾插
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] % 2 == 0)
            {
                res.insert(res.begin(), nums[i]);
            }
            else
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end
