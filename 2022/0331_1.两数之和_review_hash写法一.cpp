/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// hashmap写法一
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i)
        {
            hash[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            int tmp = target - nums[i];
            if (hash.find(tmp) != hash.end() && hash[tmp] != i)
            {
                return {i, hash[tmp]};
            }
        }
        return {};
    }
};
// @lc code=end
