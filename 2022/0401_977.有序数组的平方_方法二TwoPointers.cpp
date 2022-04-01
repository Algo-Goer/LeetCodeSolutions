/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
// 方法二：双指针
/*
数组有序，而且可能有负数，所以数组平方的最大值在数组两端
双指针从两端相向而行，依次把大的加入到res中
*/
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int k = nums.size() - 1;
        vector<int> res(k + 1, 0);
        for (int i = 0, j = k; i <= j;)
        {
            if (nums[i] * nums[i] > nums[j] * nums[j])
            {
                res[k--] = nums[i] * nums[i];
                ++i;
            }
            else
            {
                res[k--] = nums[j] * nums[j];
                --j;
            }
        }
        return res;
    }
};
// @lc code=end
