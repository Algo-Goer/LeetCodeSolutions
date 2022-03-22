/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
/*
贪心
先对数组预处理，所有数除以2，例如[0, 2, 3, 1] -> [0, 1, 1, 0]
这样便可以区分出一对对情侣
遍历数组，如果row[i] == row[i + 1]，说明情侣已经牵手，遍历下一对i + 2
如果row[i] != row[i + 1]，那么从i+2开始找row[j] = row[i]，并将row[j]与row[i + 1]交换，且count++
*/
class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        int count = 0;
        // 先对数组预处理，所有数除以2，例如[0, 2, 3, 1] -> [0, 1, 1, 0]
        for (auto &num : row)
        {
            num /= 2;
        }
        for (int i = 0; i < row.size(); i += 2)
        {
            if (row[i] != row[i + 1])
            {
                for (int j = i + 2; j < row.size(); ++j)
                {
                    if (row[j] == row[i])
                    {
                        swap(row[j], row[i + 1]);
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end
