/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> res(1 << n); // 1<<n表示2的n次方
        for (int i = 0; i < res.size(); ++i)
        {
            res[i] = (i >> 1) ^ i; // 二进制数转格雷码公式：g(i) = b(i + 1) ^ b(i)
        }
        return res;
    }
};
// @lc code=end
