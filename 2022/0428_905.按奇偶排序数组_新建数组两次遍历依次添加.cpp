/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
// code2 新建数组，两次遍历，依次添加偶数、奇数
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        vector<int> res;
        for (auto &num : nums)
        {
            if (num % 2 == 0)
                res.push_back(num);
        }
        for (auto &num : nums)
        {
            if (num % 2 != 0)
                res.push_back(num);
        }
        return res;
    }
};
// @lc code=end
