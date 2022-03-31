/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
// 二分查找写法三 return ans;  while(left <= right)
/*
举例
arr=[0,10,5,2]
left=0, right=2, mid=1
arr[mid]=10>arr[mid+1]=5, ans=mid=1, right=mid-1=0
left=0, right=0, mid=0
arr[mid]=0<arr[mid+1]=10, left=mid+1=1
left=1, right0, return ans=1

left=1, right=2, mid=1
arr[mid]=10>arr[mid+1]=5, ans=mid=1, right=mid-1=0
left=1, right=0, return ans=1
*/
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0, right = n - 2, ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1])
            {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};
// @lc code=end
