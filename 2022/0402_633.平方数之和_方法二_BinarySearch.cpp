/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
/*
code2 Binary Search 一次遍历
搜索a，判断c-a^2是否为完全平方数，接下来和[367]一样
*/
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (long a = 0; a * a <= c; ++a)
        {
            long b = c - long (a * a);
            if (binarySearch(0, sqrt(b), b))
                return true;
        }
        return false;
    }
    bool binarySearch(long l, long r, long target)
    {
        while (l <= r)
        {
            long mid = l + r >> 1; // 右移一位，表示除以2
            if (mid * mid == target)
                return true;
            else if (mid * mid < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};
// @lc code=end
