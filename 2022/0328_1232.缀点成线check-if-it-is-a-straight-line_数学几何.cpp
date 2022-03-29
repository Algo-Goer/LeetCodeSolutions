/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 */

// @lc code=start
// 几何、数组、数学
// 进阶：149.直线上最多的点数
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        if (coordinates.size() == 2)
            return true;
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];

        for (int i = 2; i < coordinates.size(); ++i)
        {
            if (dx * (coordinates[i][1] - coordinates[i - 1][1]) != dy * (coordinates[i][0] - coordinates[i - 1][0]))
                return false;
        }
        return true;
    }
};
// @lc code=end
