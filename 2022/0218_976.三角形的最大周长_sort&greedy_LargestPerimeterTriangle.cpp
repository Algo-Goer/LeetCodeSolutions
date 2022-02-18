/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */

// @lc code=start

/**
 * 给定由一些正数（代表长度）组成的数组 nums 
 * 返回 由其中三个长度组成的、面积不为零的三角形的最大周长 
 * 如果不能形成任何面积不为零的三角形，返回 0
 */
class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());   // 升序排序
        int largestPerimeter = 0;
        for (int i = nums.size() - 1; i >= 2; --i)   // 贪心算法，最大周长，所以从右往左遍历，不断更新满足条件的max
        {
            if (nums[i] < nums[i - 1] + nums[i - 2])
            {
                largestPerimeter = nums[i] + nums[i - 1] + nums[i - 2];
                return largestPerimeter;
            }  
            else 
            {
                continue;  // continue表示跳过当前循环，继续下一次循环
            }   
        }  
        return 0;   
    }
};
// @lc code=end

