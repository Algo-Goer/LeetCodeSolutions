/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
// 手写二分，用的是二分查找寻找左边界的模板，同[209]长度最小的子数组，哈希表vector形式
class Solution
{
public:
    // 手写Binary Search 二分查找寻找左边界的模板
    int binarySearch(vector<pair<int, int>>& nums, int target)
    {
        int l = 0, r = (int)nums.size() - 1; // 必须有int，数据类型一致
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid].first < target)
                l = mid + 1;
            else
                r = mid;
        }
        if (nums[l].first >= target)
            return nums[l].second; // 返回下标
        else
            return -1;
    }

    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> m; // (start, i)
        int n = (int)intervals.size();
        for (int i = 0; i < n; ++i)
        {
            m.emplace_back(intervals[i][0], i);
        }
        sort(m.begin(), m.end()); // 相当于map
        vector<int> res;
        for (auto &interval : intervals)
        {
            int target = interval[1];
            int tmp = binarySearch(m, target);
            res.emplace_back(tmp);
        }
        return res;
    }
};
// @lc code=end
