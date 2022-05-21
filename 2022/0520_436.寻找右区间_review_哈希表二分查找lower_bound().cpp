/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<int> res;
        if (intervals.empty() || intervals.size() == 1)
            return {-1};
        map<int, int> m;
        for (int i = 0; i < intervals.size(); ++i)
        {
            m[intervals[i][0]] = i; // 将左边界作为key，下标作为value
        }
        for (int i = 0; i < intervals.size(); ++i)
        {
            int r = intervals[i][1]; // 右边界
            auto it = m.lower_bound(r); // 二分查找，找到第一个大于等于r的key
            if (it == m.end())
                res.push_back(-1);
            else
                res.push_back(it->second);
        }
        return res; 
    }
};
// @lc code=end
