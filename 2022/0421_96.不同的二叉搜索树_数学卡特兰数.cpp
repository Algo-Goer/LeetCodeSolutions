/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start

// code2 卡特兰数/卡塔兰数
class Solution
{
public:
    int numTrees(int n)
    {
        long c = 1;
        for (int i = 0; i < n; ++i)
        {
            c *= 2 * (2 * i + 1);
            c /= (i + 2);
        }
        return c; 
    }
};
// @lc code=end
