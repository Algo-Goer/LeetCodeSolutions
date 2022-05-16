/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
// 计算1的个数 类[191] 
// code1 Brain Kernighan算法
class Solution
{
public:
    // 自定义 二进制表示中1的个数
    int countOnes(int x)
    {
        int ones = 0;
        while (x > 0)
        {
            x &= x - 1;
            ones++;
        }
        return ones;
    }

    vector<int> countBits(int n)
    {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            res[i] = countOnes(i);
        }
        return res;
    }
};
// @lc code=end
