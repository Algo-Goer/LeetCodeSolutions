/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
/**
 * 给你一个整数数组nums
 * 找到其中最长严格递增子序列的长度
 * 子序列是由数组派生而来的序列
 * 删除（或不删除）数组中的元素而不改变其余元素的顺序
 * 例如[3,6,2,7]是数组[0,3,1,6,2,2,7] 的子序列
 */
// 动态规划DP
/*
1、找子问题（满足无后效性，才可以写出递推式）
一个上升子序列中最右边那个数为该子序列的“终点”
2、确定状态
子问题只和一个变量——数字位置——有关。因此序列中数的位置k就是“状态”，
而状态k对应的“值”就是以ak作为“终点”的最长上升子序列的长度
状态一共有N个
3、找出状态转移方程
maxLen(k)表示以ak作为“终点”的最长上升子序列的长度，那么
初始状态：maxLen(1) = 1
maxLen(k) = max{maxLen(i): 1<=i<k且ai<ak且k!=1} + 1
若找不到这样的i，则maxLen(k) = 1
(因为ak左边任何“终点”小于ak的子序列，加上ak后就能形成一个更长的上升子序列)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int len = nums.size();
        if (len == 0) return 0;
        vector<int> dp(len, 1);  
        for (int i = 0; i < len; ++i)
        {
            dp[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    // 如果nums[j] < nums[i], 那么dp[i] = max(dp[i], dp[j] + 1)
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end()); //  *max_element(fisrt,end): 输出素组其中最大元素
    }
};
// 时间复杂度O(n^2)，空间复杂度O(n)
// @lc code=end

