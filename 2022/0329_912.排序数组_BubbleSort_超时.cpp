/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
/*
冒泡排序 时间复杂度O(n^2)
将整个数组nums分为有序和无序两部分，有序在右，无序在左，和插入排序相反
开始，整个数组无序，有序部分无元素
每次，要使得无序部分最大的元素移动到有序部分第一个元素的左边
移动方法：
依次比较相邻两个元素，如果前面的比后面的大，就交换位置
这样它的元素就像水里的气泡一样不断上浮
移动结束有序部分增加了一个元素
直到左边无序部分没有元素
*/

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = n - 1; i > 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] > nums[j + 1])
                {
                    int tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                }
            }
        }
        return nums;
    }
};
// @lc code=end
