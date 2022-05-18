/*
 * @lc app=leetcode.cn id=1346 lang=cpp
 *
 * [1346] 检查整数及其两倍数是否存在
 */

// @lc code=start
// 乘法判断 除法判断会有误差
// code3 HashSet
class Solution
{
public:
    unordered_set<int> s;
    bool checkIfExist(vector<int> &arr)
    {
        for (int num : arr)
        {
            if (s.find(num) != s.end())
                return true;
            s.insert(num * 2);
            if (num % 2 == 0)
                s.insert(num / 2);
        }
        return false;
    }
};
// @lc code=end
