/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
// 不允许使用pow(x, 0.5)或者x ** 0.5或者sqrt()
/*
二分查找
由于x平方根的整数部分ans是满足k^2<=x的最大k值，因此对k二分查找
二分查找下界0，上界粗略设定为x
在二分查找的每一步中，只需要比较中间元素mid平方与x大小关系，并调整上下界范围
由于都是整数运算，不会存在误差，因此在得到最终ans后，不需要尝试ans+1
*/
class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 0, r = x, ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end
