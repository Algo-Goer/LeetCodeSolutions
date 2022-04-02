/*
 * @lc app=leetcode.cn id=1539 lang=cpp
 *
 * [1539] 第 k 个缺失的正整数
 */

// @lc code=start
// code3 Binary Search写法二 r=n-1
/*
举例
arr=[2,3,4,7,11], k=8
l=0, r=4, mid=2, arr[mid]-mid-1=1 < k=8
l=mid+1=3, r=4, mid=3, arr[mid]-mid-1=3 < k=8
l=mid+1=4, r=4, mid=4, arr[mid]-mid-1=6 < k=8
l=mid+1=5, r=4, 不进入while循环
r+k+1=13
*/
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int l = 0, r = arr.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] - mid - 1 < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r + k + 1;   
    }
};
// @lc code=end
