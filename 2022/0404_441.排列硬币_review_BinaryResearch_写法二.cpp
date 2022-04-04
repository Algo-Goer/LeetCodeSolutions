/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
// code2 binary search 写法二 返回l或r版本
class Solution
{
public:
    int arrangeCoins(int n)
    {
        long l = 1, r = n;
        if (n == 1)
            return 1;
        while (l < r)
        {
            long mid = l + (r - l) / 2;
            if (mid * (mid + 1) / 2 <= n)
                l = mid + 1;
            else
                r = mid;
        }
        return l - 1;
        /*
        case=1,
        l=r=1，不进入while循环，此时输出为1不是0
        */
    }
};
// @lc code=end
