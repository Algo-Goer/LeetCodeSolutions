/*
 * @lc app=leetcode.cn id=1588 lang=cpp
 *
 * [1588] 所有奇数长度子数组的和
 */

// @lc code=start
// 前缀和
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prefixSum(n + 1, 0); // prefixSum[0] = 0
        for (int i = 0; i < n; ++i)
        {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
            /*
            prefixSum[0] = 0
            prefixSum[1] = prefixSum[0] + arr[0] = 0 + 1 = 1
            prefixSum[2] = prefixSum[1] + arr[1] = 1 + 4 = 5
            prefixSum[3] = prefixSum[2] + arr[2] = 5 + 2 = 7
            prefixSum[4] = prefixSum[3] + arr[3] = 7 + 5 = 12
            prefixSum[5] = prefixSum[4] + arr[4] = 12 + 3 = 15
            ...
            */
        }
        int res = 0;
        for (int start = 0; start < n; ++start)
        {
            for (int length = 1; start + length <= n; length += 2)
            {
                // 用前缀和，不用重复加，从而优化时间复杂度从O(n^2)到O(1)
                int end = start + length - 1;
                res += prefixSum[end + 1] - prefixSum[start]; 
                /*
                举例
                start=0, length=1, end=0+1-1=0, prefixSum[1] - prefixSum[0] = 1 - 0 = 1
                start=0, length=3, end=2, prefixSum[3] - prefixSum[0] = 7 - 0 = 7
                start=0, length=5, end=4, prefixSum[5] - prefixSum[0] = 15 - 0 = 15
                start=1, length=1, end=1+1-1=1, prefixSum[2] - prefixSum[1] = 5 - 1 = 4
                ...
                */
            }
        }
        return res;
    }
};
// @lc code=end
