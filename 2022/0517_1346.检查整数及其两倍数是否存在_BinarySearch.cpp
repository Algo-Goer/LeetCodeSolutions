/*
 * @lc app=leetcode.cn id=1346 lang=cpp
 *
 * [1346] 检查整数及其两倍数是否存在
 */

// @lc code=start
// 乘法判断 除法判断会有误差
// code2 Binary Search
class Solution
{
public:
    // 自定义
    bool binarySearch(vector<int> &arr, int num, int index)
    {
        int left = 0, right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] < num)
                left = mid + 1;
            else if (arr[mid] > num)
                right = mid - 1;
            else
            {
                if (mid != index)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }

    bool checkIfExist(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i)
        {
            if (binarySearch(arr, arr[i] * 2, i))
                return true;
        }
        return false;
    }
};
// @lc code=end
