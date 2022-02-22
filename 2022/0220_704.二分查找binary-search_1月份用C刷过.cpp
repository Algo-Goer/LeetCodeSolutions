/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
// /*
//  * 经典binarySearch，很多题以此为基础展开
//  * 计算 mid 时需要防止溢出
//  * 代码中 left + (right - left) / 2 就和 (left + right) / 2 的结果相同，
//  * 但是有效防止了 left 和 right 太大直接相加导致溢出。
//  */

// // 此题假设 nums 中的所有元素是不重复的。
// int search(int *nums, int numsSize, int target)
// {
//     int left = 0;
//     int right = numsSize - 1; // right指向最后一个元素的索引，而非numsSize

//     /*
//      * 如果上面right指向的是索引numsSize,那么这里是left < right,
//      * 因为如果right指向索引numsSize则出现越界
//      */

//     /*
//      * 搜索区间为空时应终止while循环
//      */

//     /*
//      * 如果while (left <= right)写错为while (left < right)，
//      * 也就是说区间[2,2]被漏掉，索引2不会被搜索， 
//      * 此时返回-1错误
//      */
//     while (left <= right) // 终止条件是：left == right + 1,即[right + 1 , right],返回-1
//     {
//         int mid = left + (right - left) / 2;
//         // 找到目标值的时候可以停止，没找到就需要while循环终止
//         if (nums[mid] == target)
//             return mid;
//         else if (nums[mid] < target)
//         /*
//          * 本算法搜索区间两端都为闭区间，即[left, right]，
//          * 当发现索引mid并非target时，就去搜索[left, mid - 1]或者[mid + 1, right]
//          * 因为mid已经搜索过了，所以应该从搜索区间中去除
//          */
//             left = mid + 1;  
//         else if (nums[mid] > target)
//             right = mid - 1;
//     }
//     // 没找到就需要while循环终止，然后返回-1
//     return -1;
// }
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        // 二分查找，设置left和right俩指针
        int left = 0;
        // 设置右指针指向最后一个元素的索引
        int right = nums.size() - 1;  // 漏掉-1会出现错误heap-buffer-overflow错误
        while (left <= right)
        {
            // 计算中间索引
            int mid = left + (right - left) / 2;
            // 如果中间索引的值等于目标值,返回中间索引
            if (nums[mid] == target)
                return mid;
            // 如果中间索引的值大于目标值,则搜索左半边
            else if (nums[mid] > target)
                right = mid - 1;
            // 如果中间索引的值小于目标值,则搜索右半边
            else
                left = mid + 1;
        }
        // 没找到返回-1
        return -1;
    }
};
// @lc code=end

