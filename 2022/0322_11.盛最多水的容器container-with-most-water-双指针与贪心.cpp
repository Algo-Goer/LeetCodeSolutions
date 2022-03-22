/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
/*
贪心+双指针
*/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        /*
        双指针
        先指向两端，此时底边最大
        贪心
        每次改变边界时，低的那根往内收
        */
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while (left < right)
        {
            max_area = max(max_area, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return max_area;
    }
};
// @lc code=end
