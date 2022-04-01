/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
// binary search
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        vector<int> ans;
        sort(nums1.begin(), nums1.end()); // 对短的数组排序
        for (auto &num : nums2)
        {
            int l = 0, r = nums1.size() - 1;
            while (l < r)
            {
                int mid = l + (r - l) / 2;
                if (nums1[mid] >= num)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (nums1[l] == num)
            {
                ans.push_back(num);             // 如果没有找到，就把短的数组的第一个数加入答案
                nums1.erase(nums1.begin() + l); // 删除已经匹配的元素
                if (!nums1.size())              // 如果短的数组已经没有元素，就不用再比较
                    break;
            }
        }
        return ans;
    }
};
// @lc code=end
