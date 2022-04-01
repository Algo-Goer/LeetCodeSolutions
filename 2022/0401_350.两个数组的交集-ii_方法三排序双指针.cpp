/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
// code4 sort & two pointers
/*
两数组排序，用双指针顺序查找相同元素
*/
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                ++i;
                ++j;
            }
            else if (nums1[i] < nums2[j])
                ++i;
            else
                ++j;
                }
        return res;
    }
};
// @lc code=end
