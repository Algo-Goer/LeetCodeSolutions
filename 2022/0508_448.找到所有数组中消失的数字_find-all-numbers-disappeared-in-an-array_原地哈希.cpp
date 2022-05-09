/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
// 原地哈希
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] != nums[nums[i] - 1]) // 各就各位的原则: i + 1 = nums[i]
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1)
                res.push_back(i + 1);
        }
        return res;
    }
};
// @lc code=end
