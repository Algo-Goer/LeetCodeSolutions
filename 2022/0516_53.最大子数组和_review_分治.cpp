/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
// code3 分治
class Solution
{
public:
    // 自定义
    int findMaxCrossingSubarray(vector<int> &nums, int left, int right, int mid)
    {
        if (left == right)
            return nums[left]; // 递归结束条件：只有一个元素在子数组
        int leftSum = 0, leftMaxSum = INT_MIN;
        for (int i = mid; i >= left; --i)
        {
            leftSum += nums[i];
            if (leftSum > leftMaxSum)
                leftMaxSum = leftSum; // 更新左边最大子数组和
        }
        int rightSum = 0, rightMaxSum = INT_MIN;
        for (int i = mid + 1; i <= right; ++i)
        {
            rightSum += nums[i];
            rightMaxSum = max(rightMaxSum, rightSum); // 更新右边最大子数组和
        }

        return leftMaxSum + rightMaxSum; // 返回左右合并后的最大子数组和
    }

    // 自定义
    int findMaxSubarray(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return nums[left];
        int mid = left + (right - left) / 2;
        int leftMaxSum = findMaxSubarray(nums, left, mid);
        int rightMaxSum = findMaxSubarray(nums, mid + 1, right);
        int crossMaxSum = findMaxCrossingSubarray(nums, left, right, mid);
        return max(max(leftMaxSum, rightMaxSum), crossMaxSum);
    }

    int maxSubArray(vector<int> &nums)
    {
        return findMaxSubarray(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
