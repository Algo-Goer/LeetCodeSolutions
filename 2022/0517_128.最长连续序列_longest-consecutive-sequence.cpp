/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
// Hashmap
class Solution
{
// 自定义
private:
    int merge(unordered_map<int, int> &map, int left, int right)
    {
        int upper = right + map[right] - 1; // 最右边数
        int lower = left - map[left] + 1;   // 最左边数
        int len = upper - lower + 1;        // 连续的长度
        map[upper] = len;                   // 更新右边界
        map[lower] = len;                   // 更新左边界
        return len;
    }

public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        unordered_map<int, int> map;
        int max_len = 1;
        for (int num : nums)
        {
            // 忽略重复值
            if (map[num])
                continue;
            map[num] = 1;
            // 连接左边元素
            if (map[num - 1])
            {
                max_len = max(max_len, merge(map, num - 1, num));
            }
            // 连接右边元素
            if (map[num + 1])
            {
                max_len = max(max_len, merge(map, num, num + 1));
            }
        }
        return max_len;
    }
};
// @lc code=end
