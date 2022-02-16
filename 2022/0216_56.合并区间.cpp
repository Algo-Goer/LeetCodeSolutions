/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
/**
 * 以数组intervals表示若干个区间的集合,其中单个区间为 intervals[i] = [starti, endi],请你合并所有重叠的区间
 * 并返回一个不重叠的区间数组,该数组需恰好覆盖输入中的所有区间
*/
/**
 * 区间题目,按照区间的起始位置排序,然后合并:
 * 如果当前区间的起始位置<=前一个区间的结束位置，则结束位置取重叠区间的最大值（两重叠区间合并）
 * 如果当前区间的起始位置>前一个区间的结束位置，则直接添加到结果集
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end()); // 按照区间的起始位置排序
        vector<vector<int>> res(1, intervals[0]); // res(1, intervals[0])代表的是一个区间，其中区间的起始位置为intervals[0][0]，结束位置为intervals[0][1]
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            if (intervals[i][0] <= res.back()[1]) // 如果当前区间的起始位置<=前一个区间的结束位置，则结束位置取重叠区间的最大值（两重叠区间合并）
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);      // 直接push_back当前区间到结果集
            }
        }
        return res;
    }
};
// @lc code=end

