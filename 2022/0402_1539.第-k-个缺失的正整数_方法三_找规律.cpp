/*
 * @lc app=leetcode.cn id=1539 lang=cpp
 *
 * [1539] 第 k 个缺失的正整数
 */

// @lc code=start
// code5 找规律arr[i]-i-1=k
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size(), i;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] - i - 1 >= k)
                return k + i;
        }
        return k + n;
    }
};
// @lc code=end
