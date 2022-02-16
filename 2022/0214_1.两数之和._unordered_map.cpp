/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

// 题目中说只会存在一个有效答案
/**
 * C++ std::unordered_map底层实现为哈希表
 * std::map和std::multimap底层实现是红黑树，key都是有序的
 * 本题不需要key有序，所以用unordered_map
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        { 
            // map.find(key)返回一个迭代器
            auto iter = map.find(target - nums[i]);  
            if (iter != map.end())
            {
                // (*it).first会得到key,(*it).second会得到value,等同于it->first和it->second
                return {i, iter->second}; 
            }
            map.insert(std::make_pair(nums[i], i));
        }
    return {};
    }
};
// @lc code=end

