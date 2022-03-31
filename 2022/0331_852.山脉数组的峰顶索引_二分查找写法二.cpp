/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
// 二分查找写法二  return mid;   while(left <= right)
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int left = 1, right = n - 2, mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])
            {
                left = mid + 1;
                continue; // continue表示继续循环
            }
            else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1])
            {
                right = mid - 1;
                continue;
            }
            return mid;
        }
        return 0; // 题目数据保证arr是一个山脉数组
    }
};
// @lc code=end
