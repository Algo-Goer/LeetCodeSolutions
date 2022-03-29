/*
 * @lc app=leetcode.cn id=1779 lang=cpp
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
 */

// @lc code=start

class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        map<int, int, less<>> res; // map<T1,T2,less<T1>>  mapA;  该容器是按键的升序方式排列元素
        // res分别存储距离和下标
        int failPoint = 0; // 不符合条件的points数
        for (int i = 0; i < points.size(); ++i)
        {
            if (x == points[i][0] || y == points[i][1])
            {
                res.insert({abs(points[i][0] - x) + abs(points[i][1] - y), i});
            }
            else
            {
                failPoint++;
            }
        }
        if (failPoint == points.size()) // 没有有效点
            return -1;
        return res.begin()->second; // 返回最近的有效点的下标
    }
};
// @lc code=end
