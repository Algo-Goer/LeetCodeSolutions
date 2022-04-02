/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
/*
code1 Two Pointers
*/
/*
c的数量级31次方，所以不能枚举
code1 Two Pointers
a^2+b^2=c^2，可知a与b都在[0,sqrt(c)]之间
经典此增彼减的关系考虑用相向而行的双指针，左指针l=0，右指针r=sqrt(c)
根据l指向元素的平方和r指向元素的平方之和与c^2的关系对左右指针进行调整

注意剪枝
right部分一定小于等于c的平方根，所以首先把right部分确定下来，再左右相向而行，直到相遇或平方和为c
*/
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long long r = sqrt(c);
        long long l = 0;
        while (l <= r)
        {
            if (l * l + r * r == c)
                return true;
            else if (l * l + r * r < c)
                l++;
            else
                r--;
        }
        return false;
    }
};
// @lc code=end
