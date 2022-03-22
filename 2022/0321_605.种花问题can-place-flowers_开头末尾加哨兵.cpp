/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
/*
在首位和尾位都各自填上一个0
有多少个0的左右两边都是0，这个数字即可以种花的最大值
*/
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int count = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);
        
        for (int i = 1; i < flowerbed.size() - 1; ++i)
        {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        } 
        return n <= count;
    }
};
// @lc code=end
