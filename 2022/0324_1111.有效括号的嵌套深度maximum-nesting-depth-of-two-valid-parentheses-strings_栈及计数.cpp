/*
 * @lc app=leetcode.cn id=1111 lang=cpp
 *
 * [1111] 有效括号的嵌套深度
 */

// @lc code=start
/*
类同LeetCode1614.括号的最大嵌套深度 Easy
本题 Medium
*/

/*
使得A和B的深度最小
贪心算法：大家深度差不多
*/

class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        vector<int> res;
        int depthA = 0, depthB = 0;
        for (auto &ch : seq)
        {
            if (ch == '(')
            {
                if (depthA <= depthB)
                {
                    depthA += 1;
                    res.push_back(0);
                }
                else
                {
                    depthB += 1;
                    res.push_back(1);
                }
            }
            else
            {
                if (depthA >= depthB)
                {
                    depthA -= 1;
                    res.push_back(0);
                }
                else
                {
                    depthB -= 1;
                    res.push_back(1);
                }
            }
        }
        return res;
    }
};
// @lc code=end
