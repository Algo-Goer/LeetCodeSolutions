/*
 * @lc app=leetcode.cn id=2176 lang=cpp
 *
 * [2176] 统计数组中相等且可以被整除的数对
 */

// @lc code=start
// Hashmap
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, vector<int>> m; // key: num, value: index
        for (int i = 0; i < n; ++i)
        {
            m[nums[i]].push_back(i); // 存储每个数字的下标
        }
        for (auto &x : m)
        {
            if (x.second.size() > 1)
            {
                for (int i = 0; i < x.second.size(); ++i)
                {
                    for (int j = i + 1; j < x.second.size(); ++j)
                    {
                        if (x.second[i] * x.second[j] % k == 0)
                            res++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

