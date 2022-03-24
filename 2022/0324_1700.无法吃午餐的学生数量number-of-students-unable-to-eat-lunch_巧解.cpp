/*
 * @lc app=leetcode.cn id=1700 lang=cpp
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start
/*
分别统计喜欢0、1的学生数量
学生顺序可调整，三明治顺序不可调整
按顺序遍历三明治数组，把三明治分给喜欢的学生，直到当前三明治没有学生喜欢
*/
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int count = 0;
        int m = sandwiches.size();
        unordered_map<int, int> map;
        for (int num : students)
        {
            // 对0、1分类计数
            map[num]++;
        }
        for (int i = 0; i < m; ++i)
        {
            if (map[sandwiches[i]] > 0) // 如果喜欢这个形状的学生数量大于0，则分这些三明治给喜欢的学生，且该计数-1
            {
                map[sandwiches[i]]--;
            }
            else
                return m - i; // 如果没有喜欢这个形状的学生，则返回剩余三明治数量
        }
        return 0;
    }
};
// @lc code=end
