/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
// 枚举
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
