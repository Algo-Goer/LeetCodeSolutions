/*
 * @lc app=leetcode.cn id=2006 lang=cpp
 *
 * [2006] 差的绝对值为 K 的数对数目
 */
/**
 * @brief 给你一个整数数组 nums 和一个整数 k
 * 请你返回数对 (i, j) 的数目
 * 满足 i < j 且 |nums[i] - nums[j]| == k 
 */

// 哈希表

// @lc code=start
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int, int> map;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            map[nums[i]]++;           // 把数组中每个元素各自都放入map中
        }
        for (int i = 0; i < n; i++)
        {
            auto iter = map.find(nums[i] - k);
            if (iter != map.end())
            {
                res += iter->second;
            }
            iter = map.find(nums[i] + k);
            if (iter != map.end())
            {
                res += iter->second;
            }
        }
        return res / 2;               // 因为每个数对都有两个，所以除以2
    }
};
// @lc code=end

