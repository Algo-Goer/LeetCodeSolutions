/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
/*
矩阵填充：
按行建立数组,比如第一行为res[0],第二行为res[1],以此类推……
从上到下遍历s,如果是空格则跳过,如果是字母则按所在的行数放入对应的数组中
返回结果:把res中的数组拼接起来
*/
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) // 第二个不要忘
            return s;
        // 遍历字符串记录字符属于哪一行，先下后上，flag=-1表示下，flag=1表示上
        vector<string> tmp(numRows, "");
        int len = s.size();
        int k = 0;
        bool flag = true;
        for (int i = 0; i < len; ++i)
        {
            tmp[k] += s[i];
            if (k == 0)
            {
                flag = true; // 下
            }
            if (k == numRows - 1)
            {
                flag = false; // 上
            }
            flag ? k++ : k--; // 判断上移还是下移
        }
        string res = "";
        for (int i = 0; i < numRows; ++i)
        {
            res += tmp[i];
        }
        return res;
    }
};
// @lc code=end
