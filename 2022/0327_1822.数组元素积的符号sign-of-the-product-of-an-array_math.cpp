/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start
// 数组、数学
class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int sign = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
                sign *= -1;
            else if (nums[i] == 0)
                return 0;
            
        }
        return sign; // 只需要判断符号就可以了，不需要去真的做乘积
    }
};
// @lc code=end
