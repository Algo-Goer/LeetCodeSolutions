/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
// 原地哈希，类似[442]数组中重复的数据
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> res(2, 0);  
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (nums[i] != i + 1) // 如果数组中下标为i的值不是i+1，就交换，直到相等，然后继续寻找
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                res[0] = nums[i]; // 重复的数字
                res[1] = i + 1;   // 丢失的数字
            }
        }
        return res;
    }
};
// @lc code=end
