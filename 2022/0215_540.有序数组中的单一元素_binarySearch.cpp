/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
/**
 * 给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次
 * 请你找出并返回只出现一次的那个数
 * 你设计的解决方案必须满足O(log n)时间复杂度和O(1)空间复杂度。 
 */
/**
 * 二分查找
 * left、right指针
 * 如果target没有出现,那么下标为(0,1)(2,3)偶-奇排列,此时偶数下标a和a+1对应元素相同
 * 如果target出现了,那么下标为(0,1)(2,3)target(4)(5,6)奇-偶排列,此时偶数下标a和a+1对应元素不同
 * 
 * 单一元素一定出现在偶数下标，且单一元素将数组分成两部分：
 * 小于单一元素的左侧部分，nums[2i] = nums[2i+1]
 * 大于单一元素的右侧部分，nums[2i] != nums[2i+1], nums[2i] = nums[2i-1]
 * 单一元素(偶数下标元素):nums[2i] != nums[2i-1] && nums[2i] != nums[2i+1]
 * 因此可以对偶数下标元素用二分查找
 */
// 1 <= nums.length <= 10^5
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1) 
            return nums[0];     // 1 <= nums.length <= 10^5,特殊情况数组只有一个元素先考虑
        if (nums[0] != nums[1]) 
            return nums[0];     // 左边界考虑
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1]; // 右边界考虑
        int low = 0; int high = n - 3;
        int mid = low + (high - low) / 2;
        while (low <= high)
        {
            if (mid % 2 != 0)
                mid += 1;       // mid统一成偶数下标
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            else if (nums[mid] == nums[mid - 1])
                high = mid - 2; // 往左边区域挪动
            else if (nums[mid] == nums[mid + 1])
                low = mid + 2;  // 往右边区域挪动
            mid = low + (high - low) / 2;   // 更新mid
        }
        return nums[mid];
    }
};
// @lc code=end

