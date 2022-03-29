/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start
// 位运算n&(n-1)表示去除n的二进制表示中最后一位的1所得的数
class Solution
{
private:
    static int countBit(int n) // 计算n的二进制表示中1的个数
    {
        int ans = 0;
        while (n)
        {
            n &= n - 1;
            ans++;
        }
        return ans;
    }
    static bool cmp(int a, int b)
    {
        int m = countBit(a), n = countBit(b);
        if (m == n)
            return a < b; // 如果两个数的二进制表示中1的个数相同，则按照二进制表示的大小排序
        else
            return m < n; // 如果两个数的二进制表示中1的个数不同，则按照二进制表示的1的个数排序
    }

public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
// @lc code=end
