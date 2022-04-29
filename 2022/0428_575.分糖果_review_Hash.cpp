/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
// HashSet
class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        unordered_set<int> candySet(candyType.begin(), candyType.end()); // 去重
        return min(candySet.size(), candyType.size() / 2);
    }
};
// @lc code=end
