/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
/*
类同LeetCode376.摆动序列
贪心
如果是I，就把剩下数字里最小的放当前位置
如果是D，就把剩下数字里最大的放当前位置
*/
class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int n = s.size();
        vector<int> res(n + 1, 0);
        int minNum = 0, maxNum = n;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'I')
            {
                res[i] = minNum;
                minNum++;
            }
            else
            {
                res[i] = maxNum;
                maxNum--;
            }
        }
        // 易错点：不要忘记最后一个位置的值
        res[n] = maxNum; 
        return res;
    }
};
// @lc code=end
