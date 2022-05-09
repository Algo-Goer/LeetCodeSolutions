/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
// 需要额外空间的哈希
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> res(2, 0);
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i)
        {
            mp[nums[i]]++;
        }
        for (int i = 0; i < n; ++i)
        {
            if (mp[i + 1] == 0)
            {
                res[1] = i + 1; // 丢失的数字
            }
            else if (mp[i + 1] == 2)
            {
                res[0] = i + 1; // 重复的数字
            }
        }
        return res;
    }
};
// @lc code=end
