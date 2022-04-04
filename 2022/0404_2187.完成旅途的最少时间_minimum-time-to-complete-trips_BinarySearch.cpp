/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 *
 * [2187] 完成旅途的最少时间
 */

// @lc code=start
// 类题目[5219]每个小孩最多能分到多少糖果 Medium
/*
binary search
*/
/*
分析
假设完成旅途的最少时间为t
关系：totalTrips = 加总(t/times[i])
*/
//  易错点：Runtime Error 整型溢出 runtime error: signed integer overflow: 10000 * 10000000 cannot be represented in type 'int' (solution.cpp)

class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long n = time.size();
        long long tot, mid;
        // 排序时间
        sort(time.begin(), time.end());
        long long l = time[0], r = (long long)time[0] * totalTrips; 
        // r边界：假设只有一辆公交车，time长度为1，此时所用的时间就是最长的
        while (l < r)
        {
            long long mid = l + (r - l) / 2;
            long long sum = 0;
            for (auto &x : time)
            {
                sum += mid / x; // 关系
            }
            if (sum >= totalTrips)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

// @lc code=end
