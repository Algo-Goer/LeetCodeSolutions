/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
/*
举例
arr=[0,2,1,0]
left=0, right=3, mid=1
arr[mid]=2>arr[mid+1]=1, right=mid=1
left=0, right=1, mid=0
arr[mid]=0<arr[mid+1]=2, left=mid+1=1
left=right=1, return left=1
*/
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
// @lc code=end
