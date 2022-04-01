/*
 * @lc app=leetcode.cn id=1385 lang=cpp
 *
 * [1385] 两个数组间的距离值
 */

// @lc code=start
// sort and binary search
/*
对arr1中的每个元素x，在排序好的arr2数组中寻找是否存在位于区间[x-d, x+d]的元素，如果存在，x不符合要求
二分查找一般是返回元素下标，本题转换为求区间长度
找到最后一个小于x-d的元素下标i1和第一个大于x+d的元素下标i2，如果i2-i1 > 1，说明存在位于[x-d, x+d]的元素，否则计数+1
*/
class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (auto &x : arr1)
        {
            int l = 0, r = arr2.size() - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (arr2[mid] - x > d)
                    r = mid - 1;
                else if (x - arr2[mid] > d)
                    l = mid + 1;
                else
                    break;
            }
            if (l > r)
                ++cnt;
        }
        return cnt;
    }
};
// @lc code=end
