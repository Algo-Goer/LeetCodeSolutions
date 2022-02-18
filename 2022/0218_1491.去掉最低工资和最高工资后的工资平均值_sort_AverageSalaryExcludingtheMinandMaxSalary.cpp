/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
 */

// @lc code=start
/**
 * 给你一个整数数组salary
 * 数组里每个数都是唯一的
 * 其中salary[i]是第i个员工的工资
 * 请你返回去掉最低工资和最高工资后剩下员工工资的平均值。
 */
class Solution {
public:
    double average(vector<int>& salary) 
    {
        int n = salary.size();
        sort(salary.begin(), salary.end()); 
        int sum = 0;
        for (int i = 1; i < n - 1; ++i)
        {
            sum += salary[i];
        }
        return sum * 1.0 / (n - 2);
    }
};


// @lc code=end

