/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
/*
先遍历，求出平方，再排序
时间复杂度O(n+nlogn)，空间复杂度O(1)
*/
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> res;
        for (auto &x : nums)
            res.push_back(x * x);
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
