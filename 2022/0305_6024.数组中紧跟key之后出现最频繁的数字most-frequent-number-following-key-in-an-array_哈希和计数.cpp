/*
给你一个下标从0开始的整数数组nums
同时给你一个整数key,它在 nums 出现过
统计在nums数组中紧跟着key后面出现的不同整数target的出现次数

换言之,target的出现次数为满足以下条件的 i 的数目：
0 <= i <= n - 2
nums[i] == key 且 nums[i + 1] == target 。
请你返回出现最多次数的target
测试数据保证出现次数最多的target是唯一的。
*/

class Solution
{
public:
    int mostFrequent(vector<int> &nums, int key)
    {
        int n = nums.size();
        // 统计key后紧跟着出现的整数，分别建立hashmap
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == key)
            {
                if (i < n - 1)
                {
                    ++m[nums[i + 1]];
                }
            }
        }
        // 用counter统计出现的次数,找出最多次数的那个数字
        int counter = 0;
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (it->second > counter)
            {
                counter = it->second; // 更新最大次数
                res = it->first;      // 更新最大次数对应的数字
            }
        }
        return res;
    }
};
// 一次通过