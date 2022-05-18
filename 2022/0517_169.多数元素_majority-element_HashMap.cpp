/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
// code3 HashMap
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> count;
        for (int num : nums)
        {
            ++count[num];
        }
        for (auto &p : count)
        {
            if (p.second > nums.size() / 2)
                return p.first;
        }
        return -1;
    }
};
// @lc code=end
