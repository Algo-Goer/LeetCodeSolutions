/*
 * @lc app=leetcode.cn id=1447 lang=cpp
 *
 * [1447] 最简分数
 */

// @lc code=start
class Solution {
public:
    vector<string> simplifiedFractions(int n) 
    {
        vector<string> res;
        for (int i = 2; i <= n; ++i)    // 分母i
        {
            for (int j = 1; j < i; ++j) // 分子j
            {
                if (__gcd(i, j) == 1)  
                // __gcd(x, y)函数:用于求x，y的最大公约数；x,y不能是浮点数
                {
                    res.push_back(to_string(j) + "/" + to_string(i));
                    // push_back:函数将一个新的元素加到vector的最后面，位置为当前最后一个元素的下一个元素
                    // to_string:将数字常量转换为字符串
                }
            }
        }
        return res;
    }
};
// @lc code=end

