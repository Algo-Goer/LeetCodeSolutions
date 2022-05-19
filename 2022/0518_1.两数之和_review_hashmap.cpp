/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// hashmap unordered_map O(1) map O(logn) 用unordered_map
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];
            if (map.count(complement)) 
                return {map[complement], i}; // 注意是{}，写成()，会出现compile error
            map[nums[i]] = i;
        }
        
        return {};
    }
};
// @lc code=end
