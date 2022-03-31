/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
// 从 2080.区间内查询数字的频率 过来，学习lower_bound()和upper_bound()
// 哈希+二分查找
/*
1、哈希：将start值和下标加入数组
2、排序
3、二分查找：在start数组中查找end位置，输出下标
*/
class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        map<int, int> start_index;
        for (int i = 0; i < intervals.size(); ++i)
        {
            start_index[intervals[i][0]] = i; // i是下标，key是satrt值，value是下标
        }
        vector<int> ans;
        for (auto &interval : intervals)
        {
            auto it = start_index.lower_bound(interval[1]);
            // lower_bound()返回的是一个迭代器，迭代器指向第一个大于等于给定值的元素，如果没有，返回end()
            // lower_bound(interval[1]) 表示查找第一个大于等于interval[1]的元素
            if (it == start_index.end()) // 没找到该元素
                ans.push_back(-1);
            else
                ans.push_back(it->second); // 返回下标
        }
        return ans;
    }
};
// @lc code=end
