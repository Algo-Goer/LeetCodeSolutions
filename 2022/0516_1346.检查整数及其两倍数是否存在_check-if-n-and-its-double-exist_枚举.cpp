/*
 * @lc app=leetcode.cn id=1346 lang=cpp
 *
 * [1346] 检查整数及其两倍数是否存在
 */

// @lc code=start
// 乘法判断 除法判断会有误差
// code1 长度最多为500，可以用枚举
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            for (int j = 0; j < arr.size(); ++j)
            {
                if (i != j && arr[i] * 2 == arr[j])
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
