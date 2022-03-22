/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
/*
贪心
从左向右遍历，可以种花就种花，n--
种花条件必须同时满足以下三个条件：
1、自己为空
2、左边为空或者自己是最左边
3、右边为空或自己是最右边
在种花过程中一旦n减到0，就直接返回true
*/
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        for (int i = 0; i < flowerbed.size(); ++i)
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
            {
                n--;
                flowerbed[i] = 1;
            }
        }     
        return n <= 0; 
    }
};
// @lc code=end
