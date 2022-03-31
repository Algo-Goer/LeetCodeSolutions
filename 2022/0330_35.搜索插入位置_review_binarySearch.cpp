/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
/*
举例
num=[1,3,5,6], target=2
left=0, right=3, mid=1, num[mid]=3>target=2, right=mid-1=0
left=0, right=0, mid=0, num[mid]=1<target=2, left=mid+1=1
left>right, 不进入while循环, return left=1

举例
num=[1,3,5,6], target=5
left=0, right=3, mid=1, num[mid]=3<target=5, left=mid+1=2
left=2, right=3, mid=2, num[mid]=5=target=6, return mid=2
*/
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        //  binary search
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                return mid;
        }
        return left;
    }
};

// @lc code=end
