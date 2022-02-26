/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 *
 * [2016] 增量元素之间的最大差值
 */

// @lc code=start
/* 
方法二：前缀和思想
一次遍历，边遍历边记录最小值
*/

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0, min_prefix = nums[0];
        for (int i = 1; i < n; ++i)
        {
            ans = max(ans, nums[i] - min_prefix);
            min_prefix = min(min_prefix, nums[i]);
        }
        // ans要么为-1，要么为正数
        return ans == 0 ? -1 : ans;
    }
};
// /*
// 方法一
// 长度小于1000，可用暴力枚举
// 找出升序序列中的最大差值
// */
// class Solution
// {
// public:
//     int maximumDifference(vector<int> &nums)
//     {
//         /*
//         双指针，i为慢指针，j为快指针
//         */
//         int ans = 0;      
//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 ans = max(ans, nums[j] - nums[i]);
//             }
//         }
//         // ans要么为-1，要么为正数
//         return ans == 0 ? -1 : ans;
//     }
// };

// @lc code=end
