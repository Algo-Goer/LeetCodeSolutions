/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
// 本题和[1]两数之和的区别在于，本题给定的是非递减顺序排列的数组，且index从1开始，要求值使用O(1)的额外空间
// 方法一 binary search
/*
先固定一个数字，再根据目标值减去第一个数得到第二个数
利用数组有序，通过二分查找寻找第二个数
因为不可以重复使用相同元素，所以在寻找第二个数字的时候，只在第一个数字右侧寻找
*/
/*
举例
number=[2,3,4], target=6
i=0, left=i+1=1, right=2
mid=1 numbers[mid]=3, target-numbers[i]=6-2=4 > numbers[mid]
left=mid+1=2
left=2, right=2
mid=2 numbers[mid]=4, target-numbers[i]=4 = numbers[mid]
return [1, 3]

numbers=[5,25,75], target=100
i=0, left=i+1=1, right=2
mid=1 numbers[mid]=25, target-numbers[i]=100-5=95 > numbers[mid]
left=mid+1=2
left=2, right=2
mid=2 numbers[mid]=75, target-numbers[i]=95 > numbers[mid]
left=mid+1=3 > right = 2不进入while循环

i=1, left=i+1=2, right=2
mid=2 numbers[mid]=75, target-numbers[i]=100-25=75 = numbers[mid]
return [2, 3]
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        for (int i = 0; i < numbers.size(); ++i)
        {
            int left = i + 1, right = numbers.size() - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == target - numbers[i])
                    return {i + 1, mid + 1};
                else if (numbers[mid] < target - numbers[i])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return {0, 0}; // 假设每个输入只对应唯一答案，所以肯定有return的最终答案，而非{0,0}。所以return {-1,-1}也可以AC
    }
};
// @lc code=end
