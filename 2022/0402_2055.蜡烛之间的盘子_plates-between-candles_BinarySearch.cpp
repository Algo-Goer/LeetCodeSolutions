/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 */

// @lc code=start
/*
code1 binary search 
查询区间内第一次出现蜡烛的位置和最后一次出现蜡烛的位置之间的距离-这个区间内蜡烛数目
*/
class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<int> pos;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '|')
                pos.push_back(i); // pos=[2,5,9]
        }
        vector<int> res;
        for (auto &x : queries)
        {
            int l = lower_bound(pos.begin(), pos.end(), x[0]) - pos.begin(); // 区间内最左边出现的位置
            // 第一个大于等于2的元素下标为0
            // x[0]=2, pos=[2,5,9], l=0-0=0
            int r = upper_bound(pos.begin(), pos.end(), x[1]) - pos.begin();
            // 第一个大于5的元素下标为2
            // x[1]=5, pos=[2,5,9], r=2=0=2
            --r;                                
            // 区间内最右边出现的位置
            // r=1
            if (r <= l)
            {
                res.push_back(0);
                continue;
            }
            int sum = (pos[r] - pos[l] + 1) - (r - l + 1); // 两个距离差+1（蜡烛+盘子数）- 蜡烛数
            // sum = 5 - 2 - (1-0+1) + 1 = 2, ans第一个元素为2
            res.push_back(sum);
        }
        return res;
    }
};
// @lc code=end
