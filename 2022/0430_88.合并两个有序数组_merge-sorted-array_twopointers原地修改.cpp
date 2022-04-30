/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
// code1 类似面试题 10.01. 合并排序的数组
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        // 使用两个指针分别指向nums1和nums2的末端，每次将较大数字加入到nums1的末尾
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while (i >= 0)
        {
            nums1[k--] = nums1[i--];
        }
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
        // 返回void类型，不需要写return
    }
};
// @lc code=end
