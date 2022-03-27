/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            map[nums[i]]++;
        }
        for (auto &item : map)
        {
            if (item.second > 1)
                return true;
        }
        return false;
    }
};
// @lc code=end
