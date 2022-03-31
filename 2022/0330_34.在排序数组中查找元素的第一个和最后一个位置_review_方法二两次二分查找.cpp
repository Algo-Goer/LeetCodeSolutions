/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
// 两次二分查找
/*
举例
[5, 7, 7, 8, 8, 10], target = 8
寻找leftBound
left=0, right=5, mid=2, nums[mid]=7<target=8, left=mid+1=3
left=3, right=5, mid=4, nums[mid]=8=target=8, res[0]=mid=4, right=mid-1=3
left=3, right=3, mid=3, nums[mid]=8=target=8, res[0]=mid=3, right=mid-1=2
left>right, 不进入while循环, 此时res[0]=3

寻找rightBound
left=0, right=5, mid=2, nums[mid]=7<target=8, left=mid+1=3
left=3, right=5, mid=4, nums[mid]=8=target=8, res[1]=mid=4, left=mid+1=5
left=5, right=5, mid=5, nums[mid]=10>target=8, right=mid-1=4
left>right, 不进入while循环, 此时res[1]=4

res=[3, 4]


[5, 7, 8], target = 6
寻找leftBound
left=0, right=2, mid=1, nums[mid]=7>target=6, right=mid-1=0
left=0, right=0, mid=0, nums[mid]=5<target=6, left=mid+1=1
left>right, 不进入while循环

寻找rightBound
left=0, right=2, mid=1, nums[mid]=7>target=6, right=mid-1=0
left=0, right=0, mid=0, nums[mid]=5<target=6, left=mid+1=1
left>right, 不进入while循环

res=[-1, -1]
*/
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res{-1, -1};                                                // 初始化为[-1, -1]
        if (nums.empty() || nums[0] > target || nums[nums.size() - 1] < target) // 升序数组，所以如果target小于首元素或大于末元素，那么返回-1
            return res;                                                         // 提示：nums长度可以为0
        int left = 0, right = nums.size() - 1;
        int flag = 0;
        int mid = left + (right - left) / 2; // 写int mid;也可
        while (left <= right)
        {
            mid = left + (right - left) / 2; // 在这里定义int mid是局部变量，需要在前面定义变量，否则下面的if (flag == 1)后left = mid;会出现Compile Error
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else // 或else if (nums[mid] == target)
            {
                // 查找到target后给res[0]赋值，继续向左二分查找
                res[0] = mid;    // 关键
                right = mid - 1; // 关键
            }
        }
        // 重置左右指针
        left = 0, right = nums.size() - 1;
        // 查找到target后，给res[1]赋值，继续向右二分查找
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else // 或else if (nums[mid] == target)
            {
                res[1] = mid;    // 关键
                left = mid + 1; // 关键
            }
        }
        return res;
    }
};
// @lc code=end
