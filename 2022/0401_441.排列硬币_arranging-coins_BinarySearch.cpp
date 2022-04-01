/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
// binary search
class Solution
{
public:
    int arrangeCoins(int n)
    {
        long l = 0, r = n;
        long tmp = 0;
        while (l <= r)
        {
            long mid = l + (r - l) / 2;
            if (mid * (mid + 1) / 2 <= n)
            {
                tmp = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return tmp;
    }
};
// @lc code=end
