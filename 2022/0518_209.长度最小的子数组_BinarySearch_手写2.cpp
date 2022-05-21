/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
// code5 Binary Search & PrefixSum
// 不用内置函数，手写二分查找
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int sumall = accumulate(nums.begin(), nums.end(), 0);
        if (!n || sumall < target)
            return 0;                    // 排除数组为空或者所有数字加和都小于target的情况
        vector<int> prefixSum(n + 1, 0); // 第一个为哑节点，这样后续有i-1时就不用特别处理第一个元素了
        for (int i = 0; i < n; ++i)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i)
        {
            int newTarget = prefixSum[i - 1] + target;
            int l = 0, r = n;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (prefixSum[mid] < newTarget)
                    l = mid + 1;
                else    
                    r = mid;
            }
            if (prefixSum[l] >= newTarget) // 也可以写成if (prefixSum[l] >= newTarget && l != n + 1)
            {
                ans = min(ans, (int)(l - i + 1)); 
            }
            else
            {
                continue;
            }
        }
        return ans;
    }
};
// @lc code=end
