/*
 * @lc app=leetcode.cn id=1748 lang=cpp
 *
 * [1748] 唯一元素的和
 */

// @lc code=start

// unique-HashTable
// 用一个哈希表记录每个元素值出现次数，然后遍历哈希表
// 累加次数为1的元素
class Solution {
public:
    int sumOfUnique(vector<int>& nums) 
    {
        unordered_map<int, int> hash;   // C++11新增unordered_map
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]]++;
        }
        for (int j = 0; j < nums.size(); j++)
        {
            if (hash[nums[j]] == 1)
            {
                ans += nums[j];
            }
        }
        return ans;
    }
};
// @lc code=end

