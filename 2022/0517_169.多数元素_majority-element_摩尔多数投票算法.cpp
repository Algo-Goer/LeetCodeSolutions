/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
// code1 博伊尔-摩尔多数投票算法
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = -1;
        int count = 0;
        for (int num : nums)
        {
            if (num == candidate)
                ++count;
            else if (--count < 0) 
            {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};
// @lc code=end
