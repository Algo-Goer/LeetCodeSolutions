/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int index = 0;
        for (int num : nums)
        {
            if (num)
            {
                nums[index++] = num; // 将非零数放前面
            }
        }
        for (int i = index; i < nums.size(); ++i)
        {
            nums[i] = 0;
        }
        return; // 可省略
    }
};
// @lc code=end
