/*
 * @lc app=leetcode.cn id=1539 lang=cpp
 *
 * [1539] 第 k 个缺失的正整数
 */

// @lc code=start
// code3 Binary Search写法一
// 给定的是严格升序排列的数组，用二分查找很不错
/*
举例
arr=[1,2,3,4], k=2
l=0, r=4, mid=2, arr[mid]=3, arr[mid]-mid-1=0 < k=2
l=mid+1=3, r=4, mid=3, arr[mid]-mid-1=0 < k=2
l=mid+1=4, r=4, 不进入while循环
l+k=4+2=6, 返回6
举例
arr=[2,3,4,7,11], k=5
l=0, r=5, mid=2, arr[mid]=4, arr[mid]-mid-1=4-2-1=1 < k=5
l=mid+1=3, r=5, mid=4, arr[mid]=11, arr[mid]-mid-1=11-4-1=6 > k=5, r=mid=4
l=3, r=4, mid=3, arr[mid]-mid-1=7-3-1=3 < k=5, l=mid+1=4
l=4, r=4, 不进入while循环
l+k=4+5=9, 返回9
*/
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int l = 0, r = arr.size(), mid = 0;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (arr[mid] - mid - 1 >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l + k;
    }
};
// @lc code=end
