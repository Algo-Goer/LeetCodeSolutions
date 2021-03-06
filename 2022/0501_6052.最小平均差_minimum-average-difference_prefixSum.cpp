/*
最小平均差
给你一个下标从 0 开始长度为 n 的整数数组 nums 。

下标 i 处的 平均差 指的是 nums 中 前 i + 1 个元素平均值和 后 n - i - 1 个元素平均值的 绝对差 。两个平均值都需要 向下取整 到最近的整数。

请你返回产生 最小平均差 的下标。如果有多个下标最小平均差相等，请你返回 最小 的一个下标。

注意：

两个数的 绝对差 是两者差的绝对值。
 n 个元素的平均值是 n 个元素之 和 除以（整数除法） n 。
0 个元素的平均值视为 0 。

输入：nums = [2,5,3,9,5,3]
输出：3
解释：
- 下标 0 处的平均差为：|2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3 。
- 下标 1 处的平均差为：|(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2 。
- 下标 2 处的平均差为：|(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2 。
- 下标 3 处的平均差为：|(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0 。
- 下标 4 处的平均差为：|(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| = |24 / 5 - 3 / 1| = |4 - 3| = 1 。
- 下标 5 处的平均差为：|(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| = |27 / 6 - 0| = |4 - 0| = 4 。
下标 3 处的平均差为最小平均差，所以返回 3 。
*/
// prefixSum
class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        // 求每个下标的平均值
        int n = nums.size();
        if (n == 1)
            return 0;
        vector<long> sums(n + 1, 0);
        vector<long> avg1(n + 1, 0);
        vector<long> avg2(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            sums[i + 1] = (long)sums[i] + (long)nums[i];
        }
        long minV = INT_MAX;
        for (int i = 0; i < n - 1; ++i)
        {
            avg1[i + 1] = sums[i + 1] / (i + 1);
            avg2[i + 1] = (sums[n] - sums[i + 1]) / (n - i - 1);
        }
        int i;
        if (int i = n - 1)
        {
            avg1[n] = sums[n] / n;
            avg2[n] = 0;
        }
        for (int i = 0; i < n; ++i)
        {
            minV = min(minV, abs(avg1[i + 1] - avg2[i + 1]));
        }
        // 返回minV对应下标i
        for (int i = 0; i < n; ++i)
        {
            if (abs(avg1[i + 1] - avg2[i + 1]) == minV)
                return i;
        }
        return -1;
    }
};