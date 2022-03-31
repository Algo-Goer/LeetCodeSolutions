/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
// binary search 提示中有对于所有i，都有nums[i]!=nums[i+1]
/*
l=0, r=n-1
如果nums[mid] > nums[mid + 1]，那么在[l, mid]这个区间一定存在一个峰值
如果nums[mid] < nums[mid + 1]，那么在[mid+1, r]区内一定存在一个峰值
*/

/*
举例
nums=[1,2,3,1]
l=0, r=3
mid=1, nums[mid]=2, nums[mid+1]=3 > nums[mid], l=mid+1=2
l=2, r=3
mid=2, nums[mid]=3, nums[mid+1]=1 < nums[mid], r=mid=2
l=r return r=2
*/
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l; //  return r;也可AC
    }
};
// @lc code=end
