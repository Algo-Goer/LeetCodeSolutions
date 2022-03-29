/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
/*
选择排序 时间复杂度O(n^2)
从n个元素中找到最小的放在第0位，和原来第0个位子上的元素交换位置
再从剩下n-1个元素中找到最小的放在第1位，以此类推，直到所有元素排序好
*/
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int len = nums.size();
        for (int i = 0; i < len - 1; ++i) // 每次循环后将第i小的元素放好
        {
            int min = i;
            // 用来记录从第i个到第size-1个元素中，最小的那个元素的下标
            for (int j = i + 1; j < len; ++j)
            {
                if (nums[j] < nums[min])
                    min = j; // 找到更小的就更新min
            }
            // 下面将第i小的元素放在第i个位子上，并把原来占着第i个位子的元素挪到后面
            if (min != i)
            {
                int tmp = nums[i];
                nums[i] = nums[min];
                nums[min] = tmp;
            }
        }
        return nums;
    }
};
// @lc code=end
