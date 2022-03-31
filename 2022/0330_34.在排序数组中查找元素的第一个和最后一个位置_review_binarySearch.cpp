/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
// 升序数组，元素可能出现多次，所以就算查到了一个target还需要继续查找下去，继续第二次二分查找
// nums[mid]与target关系-调整区间
/*
举例
[5, 7, 7, 8, 8, 10], target = 8
先寻找有没有target这个元素，有flag=1，没有flag=0
left=0<=right=5, mid=2, nums[mid]=7<8=target, left=mid+1=3
left=3<=right=5, mid=4, nums[mid]=8=8=target, flag=1,break
left=mid=4, right=mid=4, left-1>=0, nums[left-1]=8=nums[left], left--, left=3
left=3, right=4, left-1>=0, nums[left-1]=7!=8=nums[left], 所以不满足while循环条件
ans[0]=left=3
right+1=5<nums.size()=6, nums[right+1]=10>8=nums[right], 所以不满足while循环条件
ans[1]=right=4
ans=[3,4]
*/
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res{-1, -1}; // 初始化为[-1, -1]
        if (nums.empty() || nums[0] > target || nums[nums.size() - 1] < target) // 升序数组，所以如果target小于首元素或大于末元素，那么返回-1
            return res;                                                        // 提示：nums长度可以为0
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
                flag = 1;
                break;
            }
        }
        // 找到一个target后向两边搜索，因为本题有重复元素
        if (flag == 1)
        {
            left = mid;
            right = mid;
            while (left - 1 >= 0 && nums[left - 1] == nums[left]) // 注意left - 1边界条件
            {
                left--; // 注意while中left-1必须大于等于0的条件要写上
            }
            // 如果左边没有target就不会进入上述while循环，直接ans[0]=left
            res[0] = left;
            while (right + 1 < nums.size() && nums[right] == nums[right + 1]) // 注意right+1不要越界
            {
                right++; // 检查while循环条件中right+1边界
            }
            res[1] = right;
        }
        return res;
    }
};
// @lc code=end
