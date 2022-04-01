/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */

// @lc code=start
// binary search
/*
设数组一总数A，数组二总数B
A-x+y = B+x-y
x - y = (A-B)/2
对数组一排序，在数组一查找x-y这个target
*/
class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
    {
        int aliceSum = 0, bobSum = 0;
        for (auto a : aliceSizes)
        {
            aliceSum += a;
        }
        for (auto b : bobSizes)
        {
            bobSum += b;
        }
        int target = (aliceSum - bobSum) / 2;
        sort(bobSizes.begin(), bobSizes.end());
        // 对于aliceSizes中每个元素a，查找bobSizes中是否存在a-target
        for (auto a : aliceSizes)
        {
            int l = 0, r = bobSizes.size() - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (bobSizes[mid] == a - target)
                    return {a, a - target};
                else if (bobSizes[mid] < a - target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return {};
    }
};
// @lc code=end
