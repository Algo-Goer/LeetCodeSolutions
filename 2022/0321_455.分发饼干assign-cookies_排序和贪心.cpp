/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
/*
排序+贪心
先满足胃口最小的孩子，也就是先满足g[i]最小的
*/
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end()); // sort()时间复杂度O(nlogn)
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int res = 0;
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j]) // 如果孩子的胃口小于等于饼干尺寸，那么这个孩子就得到了满足，并且这块饼干还可能可以分给下一个g[i]
            {
                res++;
                i++;
            }
            // 否则，饼干不够，就需要下一块饼干
            j++;
        }
        return res;
    }
};
// @lc code=end
