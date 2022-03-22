/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
/*
贪心：尽可能保留5，所以尽可能返还10
1、如果为5，直接收下即可
2、如果为10，就要找5，如果没有，返回false
3、如果为20，就要找15：
（1）3张5（后用）
（2）1张10，1张5（先用）

维护fives和tens表示当前拥有的5和10美元钞票的张数，从前往后遍历数组分类讨论
*/

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;
        for (int bill : bills)
        {
            if (bill == 5)
            {
                ++five;
            }
            else if (bill == 10)
            {
                if (five > 0)
                {
                    --five;
                    ++ten;
                }
                else
                {
                    return false;
                }
            }
            else // 拿20，返回15
            {
                if (ten > 0 && five > 0) // 先考虑返回10+5
                {
                    --five;
                    --ten;
                }
                else if (five >= 3) // 没有10+5，再考虑3张5
                {
                    five -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
