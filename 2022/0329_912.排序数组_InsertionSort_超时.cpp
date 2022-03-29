/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
/*
插入排序 时间复杂度O(n^2)
将整个数组nums分为有序和无序两部分，有序在左，无序在右
开始有序的部分只有nums[0]，其余都属于无序部分
每次取出无序部分的第一个(最左边)元素，把它加入到有序部分
假设插入到合适位置p，则原p位置及其后面的有序部分元素都向右移动一位，有序部分即增加一个元素
*/
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); ++i)
        {
            // nums[i]是最左边的无序元素，每次循环将nums[i]放到合适位置
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] > nums[i])
                {
                    // 要把a[i]放到位置j，原下标j到i-1的元素都往后移一位
                    int tmp = nums[i];
                    for (int k = i; k > j; --k)
                    {
                        nums[k] = nums[k - 1];
                    }
                    nums[j] = tmp;
                    break;
                }
            }
        }
        return nums;
    }
};
// @lc code=end
